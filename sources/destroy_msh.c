/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_msh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:26:49 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/23 13:06:19 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_msh(t_msh msh)
{
	free_nptr(2, msh.envp);
	free_cmds(msh.cmds, msh.n_cmds);
}
