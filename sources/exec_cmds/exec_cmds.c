/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:39:13 by agerbaud          #+#    #+#             */
/*   Updated: 2024/07/19 18:05:41 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

static bool	parent_builtin(t_cmd cmd, t_msh *msh)
{
	t_builtin	builtin;

	if (!cmd.argv[0])
		return (true);
	builtin = get_builtin(cmd.argv[0]);
	if (!builtin)
		return (true);
	init_redirects(cmd, *msh);
	msh->status = builtin(cmd.argv, msh);
	dup2(msh->fd[0], STDIN_FILENO);
	dup2(msh->fd[1], STDOUT_FILENO);
	return (false);
}

static bool	update_paths(char *path_var, t_msh *msh)
{
	char		**paths;
	static char	*cache = NULL;

	if (!path_var)
	{
		free(msh->paths);
		msh->paths = NULL;
		return (false);
	}
	if (path_var == cache)
		return (false);
	paths = ft_split(path_var, ':');
	if (!paths)
	{
		perror("malloc");
		return (true);
	}
	free(msh->paths);
	msh->paths = paths;
	cache = path_var;
	return (false);
}

bool	exec_cmds(t_msh *msh)
{
	bool		status;
	size_t		i;
	t_exec_fd	fd;

	if (msh->n_cmds == 1 && !parent_builtin(msh->cmds[0], msh))
		return (false);
	fd.in = -1;
	ft_memset(&fd, -1, sizeof(fd));
	update_paths(get_env_var("PATH", 4, msh->envp), msh);
	status = false;
	i = 0;
	while (i < msh->n_cmds && !status)
	{
		status = exec_cmd(&msh->cmds[i], i + 1 == msh->n_cmds, &fd, msh);
		i++;
	}
	safe_close(&fd.in);
	msh->status = 1;
	if (status)
		return (true);
	waitpid(msh->pid, &msh->status, 0);
	msh->status = WEXITSTATUS(msh->status);
	while (wait(NULL) != -1)
		;
	return (false);
}
