/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:52:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/22 22:37:39 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_argv(char **argv)
{
	size_t	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

static void	free_redirects(t_redirect *redirects, size_t n)
{
	if (!redirects)
		return ;
	while (n--)
		free(redirects[n].name);
	free(redirects);
}

static void	free_cmd(t_cmd cmd)
{
	free_argv(cmd.argv);
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
