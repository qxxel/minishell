/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:44:37 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/16 17:45:56 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

void	remove_spaces(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		if (strs[i][0] == ' ')
			shift_strs(&strs[i]);
		else
			i++;
	}
}
