/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:10:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/23 13:12:11 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	init_envp(char **src, t_msh *msh)
{
	size_t	i;

	while (src[msh->envc])
		msh->envc++;
	msh->envp = malloc((msh->envc + 1) * sizeof(*msh->envp));
	if (!msh->envp)
	{
		perror("malloc");
		return (true);
	}
	i = -1;
	while (src[++i])
	{
		msh->envp[i] = ft_strdup(src[i]);
		if (!msh->envp[i])
		{
			perror("malloc");
			return (true);
		}
	}
	msh->envp[i] = NULL;
	return (false);
}

bool	init_msh(char **envp, t_msh *msh)
{
	ft_bzero(msh, sizeof(*msh));
	return (init_envp(envp, msh));
}
