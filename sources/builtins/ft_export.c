/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:25:37 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/09 18:09:38 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	print_envp(char **envp)
{
	size_t	i;
	size_t	id_len;

	i = 0;
	while (envp[i])
	{
		id_len = 0;
		while (envp[i][id_len] && envp[i][id_len] != '=')
			id_len++;
		envp[i][id_len] = 0;
		printf(EXPORT_PREFIX "=\"%s\"\n", envp[i], &envp[i][id_len + 1]);
		envp[i++][id_len] = '=';
	}
}

static void	print_export(t_msh msh)
{
	print_envp(msh.envp);
	while (msh.declare)
	{
		printf(EXPORT_PREFIX "\n", (char *)msh.declare->content);
		msh.declare = msh.declare->next;
	}
}

static bool	set_var(char *var, size_t id_len, t_msh *msh)
{
	t_list	*declare;

	if (!var)
	{
		perror("malloc");
		return (true);
	}
	if (var[id_len] == '=')
	{
		if (set_env_var(var, id_len, msh))
			return (true);
	}
	else
	{
		declare = ft_lstnew(var);
		if (!declare)
		{
			free(var);
			perror("malloc");
			return (true);
		}
		ft_lstadd_back(&msh->declare, declare);
	}
	return (false);
}

static bool	export_var(char *var, t_msh *msh)
{
	size_t	id_len;

	if (ft_isdigit(var[0]))
	{
		ft_dprintf(STDERR_FILENO, EXPORT_ID_ERROR, var);
		return (true);
	}
	id_len = 0;
	while (ft_isalnum(var[id_len]) || var[id_len] == '_')
		id_len++;
	if (var[id_len] && var[id_len] != '=')
	{
		ft_dprintf(STDERR_FILENO, EXPORT_ID_ERROR, var);
		return (true);
	}
	return (set_var(ft_strdup(var), id_len, msh));
}

int	ft_export(char **argv, t_msh *msh)
{
	bool	status;
	size_t	i;

	if (!argv[0] || !argv[1])
	{
		print_export(*msh);
		return (EXIT_SUCCESS);
	}
	i = 1;
	status = false;
	while (argv[i])
		status = export_var(argv[i++], msh) || status;
	return (status);
}
