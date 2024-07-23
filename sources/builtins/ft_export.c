/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:25:37 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/23 15:05:15 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static bool	print_envp(char **envp)
{
	bool	status;
	size_t	i;
	size_t	id_len;

	status = false;
	i = 0;
	while (envp[i])
	{
		id_len = 0;
		while (envp[i][id_len] && envp[i][id_len] != '=')
			id_len++;
		envp[i][id_len] = 0;
		status = printf(EXPORT_PREFIX "=\"%s\"\n", envp[i],
				&envp[i][id_len + 1]) < 0;
		envp[i++][id_len] = '=';
		if (status)
			return (write_error("export"));
	}
	return (false);
}

static bool	print_export(t_msh msh)
{
	if (print_envp(msh.envp))
		return (true);
	while (msh.declare)
	{
		if (printf(EXPORT_PREFIX "\n", (char *)msh.declare->content) < 0)
			return (write_error("export"));
		msh.declare = msh.declare->next;
	}
	return (false);
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
	if (!id_len)
	{
		ft_dprintf(STDERR_FILENO, EXPORT_ID_ERROR, "=");
		return (true);
	}
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
		return (print_export(*msh));
	i = 1;
	status = false;
	while (argv[i])
		status = export_var(argv[i++], msh) || status;
	return (status);
}
