/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_strs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:56:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/22 15:33:33 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

void	shift_strs(char **strs, bool free_str)
{
	size_t	i;

	if (free_str)
		free(strs[0]);
	i = -1;
	while (strs[++i])
		strs[i] = strs[i + 1];
}
