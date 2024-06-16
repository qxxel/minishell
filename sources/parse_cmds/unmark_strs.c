/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unmark_strs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:28:17 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/16 19:30:47 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static void	unmark_str(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if (str[i] < 0)
			str[i] *= -1;
}

void	unmark_strs(char **strs)
{
	size_t	i;

	i = -1;
	while (strs[++i])
		unmark_str(strs[i]);
}
