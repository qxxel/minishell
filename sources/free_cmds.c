/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:52:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/24 08:58:31 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_redirects(t_redirect *redirects, size_t n)
{
	if (!redirects)
		return ;
	while (n--)
		free(redirects[n].path);
	free(redirects);
}

static void	free_cmd(t_cmd cmd)
{
	free_nptr(2, cmd.argv);
	free_redirects(cmd.redirects, cmd.n_redirects);
}

void	free_cmds(t_cmd *cmds, size_t n)
{
	if (!cmds)
		return ;
	while (n--)
		free_cmd(cmds[n]);
	free(cmds);
}
