/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:03:40 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/20 16:35:55 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	remove_quotes(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		if (ft_strchr(QUOTES, strs[i][0]))
			shift_strs(&strs[i]);
		else
			i++;
	}
	return (false);
}
