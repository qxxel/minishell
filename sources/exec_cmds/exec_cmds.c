/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:39:13 by agerbaud          #+#    #+#             */
/*   Updated: 2024/07/27 01:15:20 by deydoux          ###   ########.fr       */
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
	if (!init_redirects(cmd, msh->envp))
		g_status = builtin(cmd.argv, msh);
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

static bool	test_wait_status(int status)
{
	int	sig;

	if (WIFEXITED(status))
		return (false);
	sig = WTERMSIG(status);
	if (sig == SIGINT)
		ft_putchar_fd('\n', STDERR_FILENO);
	else if (sig == SIGQUIT)
		ft_putstr_fd(SIGQUIT_MESSAGE, STDERR_FILENO);
	else if (sig == SIGSEGV)
		ft_putstr_fd(SIGSEGV_MESSAGE, STDERR_FILENO);
	g_status = SIG_BASE_STATUS + sig;
	return (true);
}

static void	wait_cmds(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	g_status = WEXITSTATUS(status);
	while (pid != -1 && !test_wait_status(status))
		pid = wait(&status);
}

bool	exec_cmds(t_msh *msh)
{
	bool		status;
	size_t		i;
	t_exec_fd	fd;

	if (!msh->n_cmds
		|| (msh->n_cmds == 1 && !parent_builtin(msh->cmds[0], msh)))
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
	g_status = 1;
	if (!status)
		wait_cmds(msh->pid);
	while (wait(NULL) != -1)
		;
	return (status);
}
