/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:39:13 by agerbaud          #+#    #+#             */
/*   Updated: 2024/06/26 19:05:31 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

bool	exec(t_cmd cmd, char **envp)
{
	char *path;
	
	path = get_path(cmd.argv[0], envp);
	if (!path)
		return (true);
	if (execve(path, cmd.argv, envp) == -1)
	perror("minishell");
	exit(1);
}

static bool	read_doc_line(char **line)
{
	if (*line)
		free(*line);
	ft_putstr_fd("> ", STDOUT_FILENO);
	*line = get_next_line(STDIN_FILENO);
	return (*line != NULL);
}

int open_heredoc(t_redirect redirect)
{
	int		fd;
	int		error;
	int		end[2];
	char	*line;

	if (pipe(end))
	{
		perror("pipe");
		return (-1);
	}
	errno = 0;
	line = NULL;
	while (read_doc_line(&line))
	{
		if(ft_strcmp(line, redirect.name) == 0)
			break ;
		ft_putstr_fd(line, end[1]);
	}
	close(end[1]);
	return(end[0]);
}

int open_redirects(t_redirect redirects)
{
	int fd;
	
	if (redirects.out)
	{
		if (!redirects.option)
			fd = open(redirects.name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		else
			fd = open(redirects.name, O_WRONLY | O_CREAT | O_APPEND, 0666);
	}
	else
	{
		if (!redirects.option)
		fd = open(redirects.name, O_RDONLY);
		if (fd == -1)
			if (access(redirects.name, F_OK))
			{
				ft_dprintf(STDERR_FILENO, "minishell: %s: No such file or directory", redirects.name);
				return (-1);
			}
	}
	if (fd == -1)
		ft_dprintf(STDERR_FILENO, "minishell: %s: Permission denied", redirects.name);
	return (fd);
}

void	check_redirects(t_cmd cmd)
{
	int	i;
	int	fd_tmp;
	
	i = 0;
	while (i < cmd.n_redirects)
	{
		fd_tmp = open_redirects(cmd.redirects[i]);
		if (fd_tmp < 0)
			exit(1);
		safe_dup2(fd_tmp, cmd.redirects[i].out);
		i++;
	}
	
}

static bool safe_dup2(int newfd, int oldfd)
{
	if (newfd == -1)
		return (false);
	if (dup2(newfd, oldfd) == -1)
	{
		perror("dup2");
		close(newfd);
		return (true);
	}
	close(newfd);
	return (false);
}

static bool	exec_cmd(t_cmd *cmd, t_msh msh, int previous_end, int end[2])
{
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		perror("fork");
		return (true);
	}
	if (cmd->pid > 0)
		return (false);
	close(end[0]);
	if (safe_dup2(previous_end, STDIN_FILENO))
		return (true);
	if (safe_dup2(end[1], STDOUT_FILENO))
		return (true);
	check_redirects(*cmd);
	exec(*cmd, msh.envp);
}

bool	exec_cmds(t_msh msh)
{
	int		end[2];
	int		previous_end;
	bool	error;
	size_t	i;

	i = 0;
	error = false;
	previous_end = -1;
	if (msh.n_cmds == 0)
		return (false);
	while (i < msh.n_cmds && !error)
	{
		if (i + 1 < msh.n_cmds)
			error = pipe(end) == -1;
		if (!error)
		{
			exec_cmd(&msh.cmds[i], msh, previous_end, end);
			error = exec_pipe(msh.cmds[i], end, msh.envp);
		}
		previous_end = end[0];
		i++;
	}
	while (i--)
		waitpid(msh.cmds[i].pid, NULL, 0);
	return (error);
}
