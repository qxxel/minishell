/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sig_exec_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:18:08 by agerbaud          #+#    #+#             */
/*   Updated: 2024/07/24 18:20:36 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_sig_exec_child(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESETHAND;
	sigaction(SIGQUIT, &act, NULL);
}