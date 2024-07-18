/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_msh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:26:49 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/18 23:27:33 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_msh_fd(int fd[2])
{
	safe_close(&fd[0]);
	safe_close(&fd[1]);
}

static void	free_msh(t_msh msh)
{
	rl_clear_history();
	free_nptr(2, msh.envp);
	free_nptr(2, msh.paths);
	free(msh.pwd);
	ft_lstclear(&msh.declare, free);
}

void	destroy_msh(t_msh msh)
{
	close_msh_fd(msh.fd);
	free_msh(msh);
}
