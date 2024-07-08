/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:38:50 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/08 12:40:53 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	parse_cmds(char *str, t_msh *msh)
{
	bool	error;
	char	**strs;

	strs = NULL;
	error = sign_expansion(str) || expand_env(&str, msh->envp)
		|| msh_split(str, &strs);
	free(str);
	error = error || expand_quotes(strs, msh->envp) || join_strs(strs)
		|| check_syntax(strs) || init_cmds(strs, msh);
	free_nptr(2, strs);
	return (error);
}
