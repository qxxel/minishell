/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:38:50 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/22 21:42:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	parse_cmds(char *str, t_msh *msh)
{
	bool	error;
	char	**strs;

	strs = NULL;
	error = sign_quotes(str) || expand_env(&str, msh->envp)
		|| msh_split(str, &strs);
	free(str);
	error = error || expand_quotes(strs, msh->envp) || join_strs(strs)
		|| check_syntax(strs) || init_cmds(strs, msh);
	free(strs);
	return (error);
}
