/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:17:48 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/09 17:50:23 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static bool	unset_envp(char *id, char ***envp)
{
	char	**new_envp;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(id);
	while ((*envp)[i]
		&& (ft_strncmp(id, (*envp)[i], len) || (*envp)[i][len] != '='))
		i++;
	if (!(*envp)[i])
		return (false);
	shift_strs(&(*envp)[i], true);
	if (init_envp(*envp, &new_envp))
		return (true);
	free_nptr(2, *envp);
	*envp = new_envp;
	return (false);
}

int	ft_unset(char **argv, t_msh *msh)
{
	size_t	i;

	if (!argv[0])
		return (EXIT_SUCCESS);
	i = 1;
	while (argv[i])
	{
		unset_declare(argv[i], &msh->declare);
		if (unset_envp(argv[i], &msh->envp))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
