/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:48:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/27 15:59:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	generate_env_var(char *id, size_t id_len, char *value, char **var)
{
	size_t	size;

	size = (id_len + ft_strlen(value) + 2) * sizeof(char);
	*var = malloc(size);
	if (!*var)
	{
		perror("malloc");
		return (true);
	}
	ft_strlcpy(*var, id, size);
	ft_strlcat(*var, "=", size);
	ft_strlcat(*var, value, size);
	return (false);
}

bool	set_env_var_id(char *id, char *value, char ***envp)
{
	char	*var;
	size_t	id_len;

	id_len = ft_strlen(id);
	return (generate_env_var(id, id_len, value, &var)
		|| set_env_var(var, id_len, envp));
}
