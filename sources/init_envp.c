/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:48:38 by deydoux           #+#    #+#             */
/*   Updated: 2024/08/01 11:52:07 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	init_envp(char **src, char ***envp)
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
			free_nptr(2, *envp);
			return (true);
		}
		i++;
	}
	(*envp)[i] = NULL;
	return (false);
}
