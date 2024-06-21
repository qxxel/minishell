/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:00:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/21 17:05:45 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static bool	join_str(char **strs)
{
	char	*str;

	str = ft_strjoin(strs[0], strs[1]);
	if (!str)
	{
		perror("malloc");
		return (true);
	}
	shift_strs(strs);
	free(strs[0]);
	strs[0] = str;
	return (false);
}

bool	join_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		if (!strs[i + 1] || ft_strchr(SEPARATORS, strs[i][0])
			|| ft_strchr(SEPARATORS, strs[i + 1][0]))
		{
			if (strs[i][0] == ' ')
				shift_strs(&strs[i]);
			else
				i++;
		}
		else
			join_str(&strs[i]);
	}
	return (false);
}
