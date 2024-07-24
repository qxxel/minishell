/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sig_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:09:21 by agerbaud          #+#    #+#             */
/*   Updated: 2024/07/24 18:35:14 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint(int sig)
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

static void	set_sigint(void)
{
	struct sigaction    act;

    ft_bzero(&act, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_handler = &handle_sigint;
	sigaction(SIGINT, &act, NULL);
}

static void set_sigquit(void)
{
    struct sigaction    act;

    ft_bzero(&act, sizeof(act));
	sigemptyset(&act.sa_mask);
    act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
}


void	set_sig_prompt(void)
{
    set_sigint();
    set_sigquit();
}
