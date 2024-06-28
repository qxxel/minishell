/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:04:15 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/28 17:10:17 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static bool	str_is_digits(char *str)
{
	size_t	i;

	i = str[0] == '+' || str[0] == '-';
	while (ft_isdigit(str[i]))
		i++;
	return (!str[i]);
}

int	ft_exit(char **argv, t_msh *msh)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (!argv[0] || !argv[1])
		exit(EXIT_SUCCESS);
	if (!str_is_digits(argv[1]))
	{
		ft_dprintf(STDERR_FILENO, EXIT_ARG_ERROR, argv[1]);
		exit(2);
	}
	if (argv[2])
	{
		ft_putstr_fd(EXIT_ARGS_ERROR, STDERR_FILENO);
		return (1);
	}
	exit(ft_atoi(argv[1]));
	(void)msh;
}
