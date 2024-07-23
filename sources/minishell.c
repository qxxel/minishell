/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:04:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/23 17:47:42 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;

void	handle_sigint(int sig)
{
	g_status = 130;
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	while (wait(NULL) != -1)
		;
	(void)sig;
}

int	main(int argc, char **argv, char **envp)
{
	bool				status;
	char				*str;
	struct sigaction	act;
	t_msh				msh;

	bzero(&act, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_handler = &handle_sigint;
	sigaction(SIGINT, &act, NULL);
	status = init_msh(envp, &msh);
	while (!status)
	{
		str = readline("$ ");
		if (!str)
		{
			ft_putstr_fd("exit\n", STDERR_FILENO);
			break ;
		}
		add_history(str);
		if (!parse_cmds(str, &msh))
			status = exec_cmds(&msh);
		free_cmds(msh.cmds, msh.n_cmds);
		msh.cmds = NULL;
		msh.n_cmds = 0;
	}
	destroy_msh(msh);
	return (status);
	(void)argc;
	(void)argv;
}
