/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:13:33 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/08 18:04:46 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"



static int	open_redirect(t_redirect redirect)
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
			return (-69420);
		else
			flag = redirect_in_flag;
	}
	fd = open(redirect.path, flag, REDIRECT_OPEN_MODE);
	if (fd < 0)
		ft_dprintf(STDERR_FILENO, FILE_ERROR, redirect.path, strerror(errno));
	return (fd);
}

void	init_redirects(t_cmd cmd)
{
	size_t	i;

	i = 0;
	while (i < cmd.n_redirects)
	{
		safe_dup2(open_redirect(cmd.redirects[i]), cmd.redirects[i].out);
		i++;
	}
}
