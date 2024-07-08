/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:29:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/08 18:38:31 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

t_builtin	get_builtin(char *name)
{
	const char		*names[] = {"cd", "echo", "env", "exit", "export", "pwd",
		"unset", NULL};
	const t_builtin	builtins[] = {ft_cd, ft_echo, ft_env, ft_exit, ft_export,
		ft_pwd, ft_unset};
	size_t			i;

	if (!name)
		return (NULL);
	i = 0;
	while (names[i])
	{
		if (!ft_strcmp(name, names[i]))
			return (builtins[i]);
		else
			i++;
	}
	return (NULL);
}
