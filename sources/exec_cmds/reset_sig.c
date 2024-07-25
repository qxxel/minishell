/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_sig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:09:57 by agerbaud          #+#    #+#             */
/*   Updated: 2024/07/25 17:43:55 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

void	reset_sig(int sig)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESETHAND;
	sigaction(sig, &act, NULL);
}
