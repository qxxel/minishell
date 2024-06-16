/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:38:50 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/16 17:08:48 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	parse_cmds(char *str, t_cmd **cmds)
{
	size_t	i;
	char	**strs;

	if (mark_quotes(str) || msh_split(str, &strs))
		return (true);
	ignore_empty_quotes(strs);
	i = -1;
	while (strs[++i])
	{
		printf("%s;\n", strs[i]);
		free(strs[i]);
	}
	free(strs);
	return (false);
	(void)cmds;
}
