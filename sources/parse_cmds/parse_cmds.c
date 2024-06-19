/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:38:50 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/19 13:47:44 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	parse_cmds(char *str, t_cmd **cmds)
{
	size_t	i;
	char	**strs;

	if (sign_quotes(str) || msh_split(str, &strs))
		return (true);
	remove_quotes(strs);
	if (join_quotes(strs))
		return (true);
	remove_spaces(strs);
	unsign_strs(strs);
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
