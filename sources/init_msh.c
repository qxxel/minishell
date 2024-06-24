/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:10:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/24 08:29:27 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	init_envp(char **src, char ***envp)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	*envp = malloc((i + 1) * sizeof(**envp));
	if (!*envp)
	{
		perror("malloc");
		return (true);
	}
	i = 0;
	while (src[i])
	{
		(*envp)[i] = ft_strdup(src[i]);
		if (!(*envp)[i])
		{
			perror("malloc");
			return (true);
		}
		i++;
	}
	(*envp)[i] = NULL;
	return (false);
}

bool	init_msh(char **envp, t_msh *msh)
{
	ft_bzero(msh, sizeof(*msh));
	return (init_envp(envp, &msh->envp));
}
