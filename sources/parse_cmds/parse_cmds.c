/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:38:50 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/21 17:00:47 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	parse_cmds(char *str, t_msh *msh)
{
	bool	error;
	char	**strs;
	size_t	i;

	strs = NULL;
	error = sign_quotes(str) || expand_env(&str, msh->envp)
		|| msh_split(str, &strs) || expand_quotes(strs, msh->envp)
		|| join_strs(strs) || unsign_strs(strs);
	if (strs)
	{
		i = -1;
		while (strs[++i])
		{
			printf("%s\n", strs[i]);
			free(strs[i]);
		}
		free(strs);
	}
	free(str);
	return (error);
}
