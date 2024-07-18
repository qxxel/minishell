/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:52:10 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/18 18:16:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(char **argv, t_msh *msh)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
	{
		perror("getcwd");
		return (EXIT_FAILURE);
	}
	if (printf("%s\n", path) < 0)
		return (write_error("pwd"));
	return (EXIT_SUCCESS);
	(void)argv;
	(void)msh;
}
