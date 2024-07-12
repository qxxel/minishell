/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:13:33 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/12 14:54:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

static int	heredoc(t_redirect redirect, char **envp)
{
	char	*str;
	int		line;
	int		pipe_fd[2];

	if (pipe(pipe_fd))
	{
		perror("pipe");
		return (-1);
	}
	line = 1;
	while (true)
	{
		str = readline("> ");
		if (!str || !ft_strcmp(redirect.path, str))
			break ;
		if (redirect.expand && expand_env(&str, envp))
		{
			safe_close(&pipe_fd[0]);
			break ;
		}
		ft_putendl_fd(str, pipe_fd[1]);
		free(str);
		line++;
	}
	free(str);
	if (!str)
		ft_dprintf(STDERR_FILENO, DELIMITER_WARNING, line, redirect.path);
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}

static int	open_redirect(t_redirect redirect, char **envp)
{
	int				fd;
	t_redirect_flag	flag;

	if (redirect.out)
	{
		if (redirect.option)
			flag = append_out_flag;
		else
			flag = redirect_out_flag;
	}
	else
	{
		if (redirect.option)
			return (heredoc(redirect, envp));
		else
			flag = redirect_in_flag;
	}
	fd = open(redirect.path, flag, REDIRECT_OPEN_MODE);
	if (fd < 0)
		ft_dprintf(STDERR_FILENO, FILE_ERROR, redirect.path, strerror(errno));
	return (fd);
}

void	init_redirects(t_cmd cmd, char **envp)
{
	size_t	i;

	i = 0;
	while (i < cmd.n_redirects)
	{
		safe_dup2(open_redirect(cmd.redirects[i], envp), cmd.redirects[i].out);
		i++;
	}
}
