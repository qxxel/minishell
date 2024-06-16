/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:38:50 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/16 16:44:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	parse_cmds(char *str, t_cmd **cmds)
{
	char	**strs;

	if (mark_quotes(str) || msh_split(str, &strs))
		return (true);
	return (false);
	(void)cmds;
}
