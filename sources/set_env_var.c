/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 08:26:17 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/09 18:21:12 by deydoux          ###   ########.fr       */
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

bool	set_env_var(char *var, size_t id_len, t_msh *msh)
{
	size_t	i;

	i = 0;
	while (msh->envp[i] && (ft_strncmp(var, msh->envp[i], id_len)
			|| msh->envp[i][id_len] != '='))
		i++;
	if (msh->envp[i])
	{
		free(msh->envp[i]);
		msh->envp[i] = var;
	}
	else if (expand_envp(var, i, &msh->envp))
		return (true);
	var[id_len] = 0;
	unset_declare(var, &msh->declare);
	var[id_len] = '=';
	return (false);
}
