/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:44:08 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/18 17:28:12 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	init_env(char **envp, t_msh *msh)
{
	char	*str;
	size_t	i;
	t_list	*new;

	i = -1;
	while (envp[++i])
	{
		str = ft_strdup(envp[i]);
		if (!str)
		{
			perror("malloc");
			return (true);
		}
		new = ft_lstnew(str);
		if (!new)
		{
			perror("malloc");
			return (true);
		}
		ft_lstadd_back(&msh->env, new);
	}
	return (false);
}
