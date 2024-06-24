/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:39:13 by agerbaud          #+#    #+#             */
/*   Updated: 2024/06/24 16:25:43 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

bool	exec(t_cmd cmd, int end[2], char **envp)
{
	path = get_path(cmd->argv[0], envp);
	if (!path)
		return (true);
	dup2(end[0], STDIN_FILENO);
	dup2(end[2], STDOUT_FILENO);
	close(end[0]);
	close(end[1]);
	close(end[2]);
	if (execve(path, cmd->argv, envp) == -1)
	{
		perror("minishell");
		exit(1);
	}
	exit(0);
}

bool	exec_pipe(t_cmd cmd, int end[3], char **envp)
{
	
	// int		i;
	// char	*path;

	// i = 0;
	// end[2] = 1;
	// if (cmd.in)
	// 	end[0] = open(cmd.in, O_RDONLY);
	// if (cmd.out)
	// 	end[2] = open(cmd.out, O_WRONLY);
	// return (exec(cmd, end, envp));
}

bool	exec_cmds(t_cmd *cmds, char **envp)
{
	int		end[3];
	bool	error;
	int		i;

	i = 0;
	error = false;
	end[0] = 0;
	if (!cmds)
		return (true);
	while (cmds[i] && !error)
	{
		if (cmds[i + 1])
			error = pipe(end + 1) == -1;
		else
			end[2] = open();
		if (!error)
			error = (end[2] == -1) || exec_pipe(cmds[i], end, envp);
		end[0] = end[1];
		exec(cmds[i]);
		i++;
	}
	return (error)
}
