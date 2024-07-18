/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:50:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/18 18:10:05 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static bool	cd_var(char *var_id, char **envp, char **path)
{
	*path = get_env_var(var_id, 0, envp);
	if (!*path)
	{
		ft_dprintf(STDERR_FILENO, CD_VAR_ERROR, var_id);
		return (true);
	}
	return (false);
}

static bool	cd_switch(char **argv, char **envp, char **path)
{
	if (!argv[0] || !argv[1])
	{
		if (cd_var("HOME", envp, path))
			return (true);
	}
	else if (argv[2])
	{
		ft_putstr_fd(CD_ARGS_ERROR, STDERR_FILENO);
		return (true);
	}
	else if (argv[1][0] == '-' && !argv[1][1])
	{
		if (cd_var("OLDPWD", envp, path))
			return (true);
		if (printf("%s\n", *path) < 0)
			return (write_error("cd"));
	}
	else
		*path = argv[1];
	return (false);
}

static bool	update_env(char *path, t_msh *msh)
{
	char	*str;

	str = get_env_var("PWD", 3, msh->envp);
	if (!str)
		str = msh->pwd;
	if (str && set_env_var_id("OLDPWD", str, msh))
		return (true);
	free(msh->pwd);
	msh->pwd = getcwd(NULL, 0);
	if (!msh->pwd)
	{
		ft_dprintf(STDERR_FILENO, CD_PARENT_ERROR, strerror(errno));
		msh->pwd = join_path(str, path);
	}
	return (!msh->pwd || set_env_var_id("PWD", msh->pwd, msh));
}

int	ft_cd(char **argv, t_msh *msh)
{
	bool	status;
	char	*path;

	status = cd_switch(argv, msh->envp, &path);
	if (!path)
		return (EXIT_FAILURE);
	if (chdir(path))
	{
		ft_dprintf(STDERR_FILENO, CD_ERROR, path, strerror(errno));
		return (EXIT_FAILURE);
	}
	return (update_env(path, msh) || status);
}
