/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 08:26:17 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/24 09:01:24 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	expand_envp(char *var, size_t size, char ***envp)
{
	char	**new_envp;

	new_envp = malloc((size + 2) * sizeof(*new_envp));
	if (!new_envp)
	{
		perror("malloc");
		return (true);
	}
	ft_memcpy(new_envp, *envp, size * sizeof(**envp));
	free(*envp);
	new_envp[size] = var;
	new_envp[size + 1] = NULL;
	*envp = new_envp;
	return (false);
}

bool	set_env_var(char *var, size_t id_len, char ***envp)
{
	size_t	i;

	i = 0;
	while ((*envp)[i] && (ft_strncmp(var, (*envp)[i], id_len)
		|| (*envp)[i][id_len] != '='))
		i++;
	if ((*envp)[i])
	{
		free((*envp)[i]);
		(*envp)[i] = var;
		return (false);
	}
	return (expand_envp(var, i, envp));
}
