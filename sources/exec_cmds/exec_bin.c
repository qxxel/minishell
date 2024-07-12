/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:32:28 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/12 14:20:31 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

static char	*get_bin_path(char *name, char **paths)
{
	char	*path;
	size_t	i;

	if (ft_strchr(name, '/'))
		return (ft_strdup(name));
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
		i++;
	while (i--)
	{
		path = join_path(paths[i], name);
		if (!path || !access(path, F_OK))
			return (path);
		free(path);
	}
	return (NULL);
}

static void	exec_bin_exit(int status, t_exec_context context)
{
	free_nptr(2, context.argv);
	free_nptr(2, context.envp);
	free(context.bin);
	exit(status);
}

static bool	access_bin(t_exec_context context)
{
	if (!context.bin)
	{
		ft_dprintf(STDERR_FILENO, CMD_ENOENT_ERROR, context.argv[0]);
		exec_bin_exit(ENOENT_EXIT_CODE, context);
	}
	if (access(context.bin, R_OK | X_OK))
	{
		ft_dprintf(STDERR_FILENO, FILE_ERROR, context.bin, strerror(errno));
		if (errno == ENOENT)
			exec_bin_exit(ENOENT_EXIT_CODE, context);
		else if (errno == EACCES)
			exec_bin_exit(EACCES_EXIT_CODE, context);
		return (true);
	}
	return (false);
}

void	exec_bin(t_cmd *cmd, t_msh *msh)
{
	char			**paths;
	t_exec_context	context;

	context.argv = cmd->argv;
	context.envp = msh->envp;
	paths = msh->paths;
	if (context.argv[0])
	{
		cmd->argv = NULL;
		msh->envp = NULL;
		msh->paths = NULL;
	}
	free_cmds(msh->cmds, msh->n_cmds);
	destroy_msh(*msh);
	if (!context.argv[0])
		return ;
	context.bin = get_bin_path(context.argv[0], paths);
	free_nptr(2, paths);
	if (!access_bin(context) && execve(context.bin, context.argv, context.envp))
		perror("execve");
	exec_bin_exit(EXIT_FAILURE, context);
}
