/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:09:17 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/26 15:28:29 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_env(char **argv, t_msh *msh)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (msh->envp[i])
	{
		len = ft_strlen(msh->envp[i]);
		msh->envp[i][len] = '\n';
		write(STDOUT_FILENO, msh->envp[i], len + 1);
		msh->envp[i][len] = 0;
		i++;
	}
	return (EXIT_SUCCESS);
	(void)argv;
}
