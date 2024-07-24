/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:22:29 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/24 15:49:15 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

static void	exec_builtin(t_cmd *cmd, t_msh *msh)
{
	int			status;
	t_builtin	builtin;

	builtin = get_builtin(cmd->argv[0]);
	if (!builtin)
		return ;
	status = builtin(cmd->argv, msh);
	free_cmds(msh->cmds, msh->n_cmds);
	destroy_msh(*msh);
	exit(status);
}

static bool	exec_cmd_child(t_cmd *cmd, bool last, t_exec_fd fd, t_msh *msh)
{
	struct sigaction	act;

	msh->pid = fork();
	if (msh->pid)
	{
		if (msh->pid < 0)
		{
			perror("fork");
			return (true);
		}
		return (false);
	}
	if (!last)
	{
		close(fd.pipe[0]);
		safe_dup2(fd.pipe[1], STDOUT_FILENO);
	}
	safe_dup2(fd.in, STDIN_FILENO);
	ft_bzero(&act, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESETHAND;
	sigaction(SIGINT, &act, NULL);
	if (!init_redirects(*cmd, msh->envp))
	{
		sigaction(SIGQUIT, &act, NULL);
		exec_builtin(cmd, msh);
		exec_bin(cmd, msh);
	}
	free_cmds(msh->cmds, msh->n_cmds);
	destroy_msh(*msh);
	exit(EXIT_FAILURE);
}

bool	exec_cmd(t_cmd *cmd, bool last, t_exec_fd *fd, t_msh *msh)
{
	if (!last && pipe(fd->pipe))
	{
		perror("pipe");
		return (true);
	}
	exec_cmd_child(cmd, last, *fd, msh);
	safe_close(&fd->in);
	fd->in = fd->pipe[0];
	safe_close(&fd->pipe[1]);
	return (false);
}
