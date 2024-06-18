/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:46:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/18 18:05:43 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var(char *name, size_t len, t_list *env)
{
	if (!len)
		len = ft_strlen(name);
	while (env && (ft_strncmp(name, env->content, len)
			|| ((char *)env->content)[len] != '='))
		env = env->next;
	if (!env)
		return (NULL);
	return (&env->content[len + 1]);
}
