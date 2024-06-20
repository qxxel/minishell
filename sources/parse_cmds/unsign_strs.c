/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_strs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:28:17 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/20 16:37:38 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static void	unsign_str(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if ((signed char)str[i] < 0)
			str[i] *= -1;
}

bool	unsign_strs(char **strs)
{
	size_t	i;

	i = -1;
	while (strs[++i])
		unsign_str(strs[i]);
	return (false);
}
