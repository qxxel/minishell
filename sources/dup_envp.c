/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:44:08 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/20 16:59:57 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	dup_envp(char **src, t_msh *msh)
{
	size_t	i;

	while (src[msh->envc])
		msh->envc++;
	msh->envp = malloc((msh->envc + 1) * sizeof(*msh->envp));
	if (!msh->envp)
	{
		perror("malloc");
		return (true);
	}
	i = -1;
	while (src[++i])
	{
		msh->envp[i] = ft_strdup(src[i]);
		if (!msh->envp[i])
		{
			perror("malloc");
			return (true);
		}
	}
	msh->envp[i] = NULL;
	return (false);
}
