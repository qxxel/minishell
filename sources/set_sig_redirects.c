/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sig_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:09:57 by agerbaud          #+#    #+#             */
/*   Updated: 2024/07/24 18:16:40 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_sig_redirects(void)
{
	struct sigaction    act;

    ft_bzero(&act, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESETHAND;
	sigaction(SIGINT, &act, NULL);
}