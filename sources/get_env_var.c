/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:46:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/23 13:15:01 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var(char *name, size_t len, char **envp)
{
	size_t	i;

	if (!len)
		len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(name, envp[i], len) && envp[i][len] == '=')
			return (&envp[i][len + 1]);
		i++;
	}
	return (NULL);
}
