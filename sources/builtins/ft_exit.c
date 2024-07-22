/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:04:15 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/22 18:37:21 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static bool	safe_atoll(char *str, long long *n)
{
	char		sign;
	long long	tmp_n;

	sign = 1;
	tmp_n = 0;
	*n = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign -= 2 * (*str++ == '-');
	while (ft_isdigit(*str))
	{
		tmp_n = tmp_n * 10 + (*str++ - '0') * sign;
		if (*n != tmp_n / 10)
			return (true);
		*n = tmp_n;
	}
	return (*str != 0);
}

int	ft_exit(char **argv, t_msh *msh)
{
	long long	status;

	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (!argv[0] || !argv[1])
		status = EXIT_SUCCESS;
	else if (safe_atoll(argv[1], &status))
	{
		ft_dprintf(STDERR_FILENO, EXIT_ARG_ERROR, argv[1]);
		status = 2;
	}
	else if (argv[2])
	{
		ft_putstr_fd(EXIT_ARGS_ERROR, STDERR_FILENO);
		return (1);
	}
	free_cmds(msh->cmds, msh->n_cmds);
	destroy_msh(*msh);
	exit(status);
}
