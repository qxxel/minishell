/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_msh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:26:49 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/09 14:47:40 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_fd(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

static void	free_msh(t_msh msh)
{
	clear_history();
	free_nptr(2, msh.envp);
	free_cmds(msh.cmds, msh.n_cmds);
	ft_lstclear(&msh.declare, free);
}

void	destroy_msh(t_msh msh)
{
	close_fd(msh.fd);
	free_msh(msh);
}
