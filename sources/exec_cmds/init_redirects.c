/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:13:33 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/27 02:18:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

static int	open_redirect(t_redirect redirect, t_msh msh)
{
	int				fd;
	t_redirect_flag	flag;

	if (redirect.out)
	{
		if (redirect.option)
			flag = append_out_flag;
		else
			flag = redirect_out_flag;
	}
	else
	{
		if (redirect.option)
			return (heredoc(redirect, msh));
		else
			flag = redirect_in_flag;
	}
	fd = open(redirect.path, flag, REDIRECT_OPEN_MODE);
	if (fd < 0)
	{
		g_status = 1;
		ft_dprintf(STDERR_FILENO, FILE_ERROR, redirect.path, strerror(errno));
	}
	return (fd);
}

bool	init_redirects(t_cmd cmd, t_msh msh)
{
	int		fd;
	size_t	i;

	i = 0;
	while (i < cmd.n_redirects)
	{
		fd = open_redirect(cmd.redirects[i], msh);
		if (fd < 0)
			return (true);
		safe_dup2(fd, cmd.redirects[i].out);
		i++;
	}
	return (false);
}
