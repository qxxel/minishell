/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_msh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:26:49 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/20 16:59:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	destroy_envp(char **envp)
{
	size_t	i;

	if (!envp)
		return ;
	i = -1;
	while (envp[++i])
		free(envp[i]);
	free(envp);
}

void	destroy_msh(t_msh msh)
{
	destroy_envp(msh.envp);
}
