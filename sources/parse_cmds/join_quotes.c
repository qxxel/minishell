/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:00:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/21 14:17:07 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	join_quotes(char **strs)
{
	char	*str;
	size_t	i;

	i = 0;
	while (strs[i])
	{
		if (!strs[i + 1] || ft_strchr(SEPARATORS, strs[i][0])
			|| ft_strchr(SEPARATORS, strs[i + 1][0]))
		{
			i++;
			continue ;
		}
		str = ft_strjoin(strs[i], strs[i + 1]);
		if (!str)
		{
			perror("malloc");
			return (true);
		}
		shift_strs(&strs[i]);
		free(strs[i]);
		strs[i] = str;
	}
	return (false);
}
