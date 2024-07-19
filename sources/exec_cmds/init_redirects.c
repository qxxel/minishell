/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:13:33 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/19 18:29:04 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

static void	heredoc_read(t_redirect redirect, t_msh msh,
	t_heredoc_context *context)
{
	while (true)
	{
		context->str = readline("> ");
		if (!context->str || !ft_strcmp(redirect.path, context->str))
			return ;
		if (redirect.expand && expand_env(&context->str, msh))
		{
			safe_close(&context->pipe[0]);
			return ;
		}
		ft_putendl_fd(context->str, context->pipe[1]);
		free(context->str);
		context->line++;
	}
}

static int	heredoc(t_redirect redirect, t_msh msh)
{
	t_heredoc_context	context;

	if (pipe(context.pipe))
	{
		perror("pipe");
		return (-1);
	}
	context.line = 1;
	heredoc_read(redirect, msh, &context);
	free(context.str);
	if (!context.str)
		ft_dprintf(STDERR_FILENO, DELIMITER_WARNING, context.line,
			redirect.path);
	close(context.pipe[1]);
	return (context.pipe[0]);
}

static int	open_redirect(t_redirect redirect, t_msh msh)
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
			return (heredoc(redirect, msh));
		else
			flag = redirect_in_flag;
	}
	fd = open(redirect.path, flag, REDIRECT_OPEN_MODE);
	if (fd < 0)
		ft_dprintf(STDERR_FILENO, FILE_ERROR, redirect.path, strerror(errno));
	return (fd);
}

bool	init_redirects(t_cmd cmd, t_msh msh)
{
	int		fd;
	size_t	i;

	i = 0;
	while (i < cmd.n_redirects)
	{
		fd = open_redirect(cmd.redirects[i], msh);
		if (fd < 0)
			return (true);
		safe_dup2(fd, cmd.redirects[i].out);
		i++;
	}
	return (false);
}
