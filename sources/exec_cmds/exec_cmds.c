/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:39:13 by agerbaud          #+#    #+#             */
/*   Updated: 2024/07/09 15:56:57 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

static bool	parent_builtin(t_cmd cmd, t_msh *msh)
{
	t_builtin	builtin;

	if (!cmd.argv[0])
		return (false);
	builtin = get_builtin(cmd.argv[0]);
	if (!builtin)
		return (false);
	init_redirects(cmd, msh->envp);
	msh->status = builtin(cmd.argv, msh);
	dup2(msh->fd[0], STDIN_FILENO);
	dup2(msh->fd[1], STDOUT_FILENO);
	return (true);
}

static bool	exec_cmd_child(t_cmd *cmd, t_exec_fd fd, t_msh *msh)
{
	t_builtin	builtin;

	cmd->pid = fork();
	if (cmd->pid)
	{
		if (cmd->pid < 0)
		{
			perror("fork");
			return (true);
		}
		return (false);
	}
	close(fd.pipe[0]);
	safe_dup2(fd.in, STDIN_FILENO);
	safe_dup2(fd.pipe[1], STDOUT_FILENO);
	init_redirects(*cmd, msh->envp);
	builtin = get_builtin(cmd->argv[0]);
	if (builtin)
		exit(builtin(cmd->argv, msh));
	exit(EXIT_FAILURE);
}

static bool	exec_cmd(t_cmd *cmd, bool last, t_exec_fd *fd, t_msh *msh)
{
	if (last && pipe(fd->pipe))
	{
		perror("pipe");
		return (true);
	}
	exec_cmd_child(cmd, *fd, msh);
	safe_close(&fd->in);
	fd->in = fd->pipe[0];
	safe_close(&fd->pipe[1]);
	return (false);
}

bool	exec_cmds(t_msh *msh)
{
	bool		status;
	size_t		i;
	t_exec_fd	fd;

	if (msh->n_cmds == 1 && parent_builtin(msh->cmds[0], msh))
		return (false);
	fd.in = -1;
	ft_memset(&fd, -1, sizeof(fd));
	i = 0;
	while (i < msh->n_cmds && !status)
	{
		status = exec_cmd(&msh->cmds[i], i + 1 != msh->n_cmds, &fd, msh);
		i++;
	}
	safe_close(&fd.in);
	if (!status)
		waitpid(msh->cmds[--i].pid, &msh->status, 0);
	while (i--)
		waitpid(msh->cmds[i].pid, NULL, 0);
	return (status);
}
