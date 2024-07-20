/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:09:17 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/20 13:28:20 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_env(char **argv, t_msh *msh)
{
	bool	status;
	size_t	i;
	size_t	len;

	status = false;
	i = 0;
	while (msh->envp[i] && !status)
	{
		len = ft_strlen(msh->envp[i]);
		msh->envp[i][len] = '\n';
		if (write(STDOUT_FILENO, msh->envp[i], len + 1) < 0)
			status = write_error("env");
		msh->envp[i][len] = 0;
		i++;
	}
	return (status);
	(void)argv;
}
