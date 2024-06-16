/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:00:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/16 17:43:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	join_quotes(char **strs)
{
	char	*str;
	size_t	i;

	i = 0;
	while (strs[++i])
	{
		if (ft_strchr(SEPARATORS, strs[i - 1][0])
			|| ft_strchr(SEPARATORS, strs[i][0]))
			continue ;
		str = ft_strjoin(strs[i - 1], strs[i]);
		if (!str)
		{
			perror("malloc");
			return (true);
		}
		shift_strs(&strs[i - 1]);
		free(strs[i - 1]);
		strs[i - 1] = str;
	}
	return (false);
}
