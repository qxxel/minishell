/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:39:13 by agerbaud          #+#    #+#             */
/*   Updated: 2024/06/24 17:15:07 by agerbaud         ###   ########.fr       */
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

bool	exec_pipe(t_cmd cmd, int end[2], char **envp)
{
	int		i;
	char	*path;

	i = 0;
	
}

bool	check_redirections(t_msh msh, int end[2], int prev_end,size_t i)
{
	int	j;
	int	fd_tmp;
	
	j = 0;
	msh.cmds[i].pid = fork();
	if (msh.cmds[i].pid == -1)
		return (true);
	if (msh.cmds[i].pid > 0)
		return (false);
	dup2(prev_end, STDIN_FILENO);
	close(prev_end);
	close(end[0]);
	dup2(end[1], STDOUT_FILENO);
	close(end[1]);
	while (j < msh.cmds->n_redirects)
	{
		fd_tmp = open(msh.cmds->redirects[j].name, );
		if (fd_tmp < 0)
			exit(1);
		dup2(fd_tmp, end[1]);
		close (fd_tmp);
		j++;
	}
	exit(0);
}

bool	exec_cmds(t_msh msh)
{
	int		end[2];
	int		previous_end;
	bool	error;
	size_t	i;

	i = 0;
	error = false;
	if (msh.n_cmds == 0)
		return (false);
	while (i < msh.n_cmds && !error)
	{
		if (i + 1 < msh.n_cmds)
			error = pipe(end) == -1;
		if (!error)
		{
			if (check_redirections(msh, end, previous_end, i) == true)
				return (true);
			error = (end[0] == -1) || exec_pipe(msh.cmds[i], end, msh.envp);
		}
		previous_end = end[0];
		i++;
	}
	return (error)
}
