/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:25:37 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/26 15:29:22 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	print_export(char **envp)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (envp[i])
	{
		len = 0;
		while (envp[i][len] && envp[i][len] != '=')
			len++;
		if (!envp[i][len])
			printf(EXPORT_PREFIX "%s\n", envp[i]);
		else
		{
			envp[i][len] = 0;
			printf(EXPORT_PREFIX "%s=\"%s\"\n", envp[i], &envp[i][len + 1]);
			envp[i][len] = '=';
		}
		i++;
	}
}

static bool	export_var(char *var, char ***envp)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	return (false);
}

int	ft_export(char **argv, t_msh *msh)
{
	size_t	i;

	if (!argv[0] || !argv[1])
		print_export(msh->envp);
	i = 1;
	while (argv[i])
		i++;
	return (EXIT_SUCCESS);
}
