/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:52:10 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/27 13:58:56 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(char **argv, t_msh *msh)
{
	char	*path;
	int		status;

	path = getcwd(NULL, 0);
	if (!path)
	{
		perror("getcwd");
		return (EXIT_FAILURE);
	}
	status = printf("%s\n", path) < 0;
	free(path);
	if (status)
		return (write_error("pwd"));
	return (EXIT_SUCCESS);
	(void)argv;
	(void)msh;
}
