/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:09:17 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/24 07:17:42 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_env(char **argv, char ***envp)
{
	size_t	i;
	size_t	len;

	i = 0;
	while ((*envp)[i])
	{
		len = ft_strlen((*envp)[i]);
		(*envp)[i][len] = '\n';
		write(STDOUT_FILENO, (*envp)[i], len + 1);
		(*envp)[i][len] = 0;
		i++;
	}
	return (EXIT_SUCCESS);
	(void)argv;
}
