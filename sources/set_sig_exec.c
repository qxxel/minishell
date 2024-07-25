/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sig_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:09:21 by agerbaud          #+#    #+#             */
/*   Updated: 2024/07/25 15:49:07 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint(int sig)
{
	g_status = SIGINT_CODE;
	while (wait(NULL) != -1)
		;
	ft_putchar_fd('\n', STDERR_FILENO);
	(void)sig;
}

void	set_sig_exec(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_handler = &handle_sigint;
	sigaction(SIGINT, &act, NULL);
}
