/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:44:08 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/18 12:03:36 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	init_envp(char **initial, t_msh	*msh)
{
	char	*str;
	size_t	i;
	t_list	*new;

	i = -1;
	while (initial[++i])
	{
		str = ft_strdup(initial[i]);
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
		ft_lstadd_back(&msh->envp, new);
	}
	return (false);
}
