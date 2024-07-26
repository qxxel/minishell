/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:44:20 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/26 11:04:23 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

static void	handle_sigint(int sig)
{
	g_status = SIG_BASE_STATUS + sig;
	ft_putchar_fd('\n', STDERR_FILENO);
	close(STDIN_FILENO);
}

static void	set_sig(void)
{
	struct sigaction	act;

	g_status = false;
	act.sa_flags = SA_RESTART;
	act.sa_handler = &handle_sigint;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);
}

static void	heredoc_read(t_redirect redirect, char **envp,
	t_heredoc_context *context)
{
	while (true)
	{
		context->str = readline("> ");
		if (!context->str || !ft_strcmp(redirect.path, context->str))
			return ;
		if (redirect.expand && expand_env(&context->str, envp))
		{
			safe_close(&context->pipe[0]);
			return ;
		}
		ft_putendl_fd(context->str, context->pipe[1]);
		free(context->str);
		context->line++;
	}
}

int	heredoc(t_redirect redirect, char **envp)
{
	t_heredoc_context	context;

	if (pipe(context.pipe))
	{
		perror("pipe");
		return (-1);
	}
	context.line = 1;
	set_sig();
	heredoc_read(redirect, envp, &context);
	ignore_sig(SIGINT);
	free(context.str);
	if (g_status)
		safe_close(&context.pipe[0]);
	else if (!context.str)
		ft_dprintf(STDERR_FILENO, DELIMITER_WARNING, context.line,
			redirect.path);
	close(context.pipe[1]);
	return (context.pipe[0]);
}
