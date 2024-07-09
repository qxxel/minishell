/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:10:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/09 18:12:49 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	dup_std_fd(int fd[2])
{
	ft_memset(fd, -1, sizeof(int [2]));
	fd[0] = dup(STDIN_FILENO);
	if (fd[0] < 0)
	{
		perror("dup");
		return (true);
	}
	fd[1] = dup(STDOUT_FILENO);
	if (fd[1] < 0)
	{
		perror("dup");
		return (true);
	}
	return (false);
}

static bool	restore_pwd_env(t_msh *msh)
{
	bool	status;
	char	*str;

	status = false;
	if (!get_env_var("PWD", 3, msh->envp))
	{
		str = getcwd(NULL, 0);
		if (!str)
		{
			perror("getcwd");
			return (true);
		}
		status = set_env_var_id("PWD", str, msh);
		free(str);
	}
	return (status);
}

static bool	update_shlvl_env(t_msh *msh)
{
	bool	status;
	char	*str;
	int		shlvl;

	str = get_env_var("SHLVL", 5, msh->envp);
	if (!str)
		return (set_env_var_id("SHLVL", "1", msh));
	shlvl = ft_atoi(str) + 1;
	if (shlvl < 0)
		shlvl = 0;
	str = ft_itoa(shlvl);
	if (!str)
	{
		perror("malloc");
		return (true);
	}
	status = set_env_var_id("SHLVL", str, msh);
	free(str);
	return (status);
}

bool	init_msh(char **envp, t_msh *msh)
{
	ft_bzero(msh, sizeof(*msh));
	dup_std_fd(msh->fd);
	return (init_envp(envp, &msh->envp) || restore_pwd_env(msh)
		|| update_shlvl_env(msh));
}
