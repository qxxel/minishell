/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:10:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/08 16:43:50 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dup_std_fd(t_msh *msh)
{
	msh->fd[0] = dup(STDIN_FILENO);
	msh->fd[1] = dup(STDOUT_FILENO);
}

bool	init_msh(char **envp, t_msh *msh)
{
	ft_bzero(msh, sizeof(*msh));
	dup_std_fd(msh);
	return (init_envp(envp, &msh->envp));
}
