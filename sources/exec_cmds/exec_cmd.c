/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:22:29 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/11 16:04:19 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

static void	exec_builtin(t_cmd *cmd, t_msh *msh)
{
	int			status;
	t_builtin	builtin;

	builtin = get_builtin(cmd->argv[0]);
	if (!builtin)
		return ;
	status = builtin(cmd->argv, msh);
	free_cmds(msh->cmds, msh->n_cmds);
	destroy_msh(*msh);
	exit(status);
}

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

static void	exec_bin(t_cmd *cmd, t_msh *msh)
{
	char	**argv;
	char	**envp;
	char	**paths;
	char	*bin_path;

	argv = cmd->argv;
	envp = msh->envp;
	paths = msh->paths;
	if (argv[0])
	{
		cmd->argv = NULL;
		msh->envp = NULL;
		msh->paths = NULL;
	}
	free_cmds(msh->cmds, msh->n_cmds);
	destroy_msh(*msh);
	if (!argv[0])
		return ;
	bin_path = get_bin_path(argv[0], paths);
	free_nptr(2, paths);
	if (!bin_path)
	{
		ft_dprintf(STDERR_FILENO, CMD_ENOENT_ERROR, argv[0]);
		exit(ENOENT_EXIT_CODE);
	}
	if (access(bin_path, R_OK | X_OK))
	{
		ft_dprintf(STDERR_FILENO, FILE_ERROR, bin_path, strerror(errno));
		if (errno == ENOENT)
			exit(ENOENT_EXIT_CODE);
		else if (errno == EACCES)
			exit(EACCES_EXIT_CODE);
	}
	else if (execve(bin_path, argv, envp))
		perror("execve");
}

static bool	exec_cmd_child(t_cmd *cmd, bool last, t_exec_fd fd, t_msh *msh)
{
	cmd->pid = fork();
	if (cmd->pid)
	{
		if (cmd->pid < 0)
		{
			perror("fork");
			return (true);
		}
		return (false);
	}
	if (!last)
	{
		close(fd.pipe[0]);
		safe_dup2(fd.pipe[1], STDOUT_FILENO);
	}
	safe_dup2(fd.in, STDIN_FILENO);
	init_redirects(*cmd, msh->envp);
	exec_builtin(cmd, msh);
	exec_bin(cmd, msh);
	exit(EXIT_FAILURE);
}

bool	exec_cmd(t_cmd *cmd, bool last, t_exec_fd *fd, t_msh *msh)
{
	if (!last && pipe(fd->pipe))
	{
		perror("pipe");
		return (true);
	}
	exec_cmd_child(cmd, last, *fd, msh);
	safe_close(&fd->in);
	fd->in = fd->pipe[0];
	safe_close(&fd->pipe[1]);
	return (false);
}
