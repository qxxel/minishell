/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:38:50 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/18 14:30:25 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	parse_cmds(char *str, t_msh *msh)
{
	bool	status;
	char	**strs;

	strs = NULL;
	status = sign_expansion(str) || expand_env(&str, msh->envp)
		|| expand_wildcards(&str) || msh_split(str, &strs);
	free(str);
	status = status || expand_quotes(strs, msh->envp) || join_strs(strs)
		|| check_syntax(strs) || init_cmds(strs, msh);
	free_nptr(2, strs);
	return (status);
}
