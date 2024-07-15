/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_dup2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:56:41 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/09 14:38:01 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

void	safe_dup2(int new_fd, int old_fd)
{
	if (new_fd < 0)
		return ;
	dup2(new_fd, old_fd);
	close(new_fd);
}
