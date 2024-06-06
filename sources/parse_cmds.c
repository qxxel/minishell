/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:24:36 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/06 14:33:20 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	parse_cmd(char *str)
{
	(void)str;
	return (false);
}

bool	parse_cmds(char *str)
{
	char	**strs;
	size_t	i;

	strs = ft_split(str, '|');
	if (!strs)
		return (true);
	i = -1;
	while (strs[++i])
	{
		if (parse_cmd(strs[i]))
			break ;
		free(strs[i]);
	}
	if (!strs[i])
		return (false);
	while (strs[i])
		free(strs[i++]);
	return (true);
}
