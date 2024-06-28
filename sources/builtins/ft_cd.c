/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:50:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/28 13:03:02 by deydoux          ###   ########.fr       */
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
		printf("%s\n", *path);
	}
	else
		*path = argv[1];
	return (false);
}

static bool	set_pwd(char *old_pwd, char *pwd, char ***envp)
{
	bool	status;

	status = !pwd;
	if (status)
		perror("getcwd");
	status = status || set_env_var_id("PWD", pwd, envp)
		|| set_env_var_id("OLDPWD", old_pwd, envp);
	free(pwd);
	free(old_pwd);
	return (status);
}

int	ft_cd(char **argv, t_msh *msh)
{
	char	*old_pwd;
	char	*path;

	if (cd_switch(argv, msh->envp, &path))
		return (EXIT_FAILURE);
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
	{
		perror("getcwd");
		return (EXIT_FAILURE);
	}
	if (chdir(path))
	{
		free(old_pwd);
		ft_dprintf(STDERR_FILENO, CD_ERROR, path, strerror(errno));
		return (EXIT_FAILURE);
	}
	return (set_pwd(old_pwd, getcwd(NULL, 0), &msh->envp));
}
