/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:33:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/19 17:39:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_CMDS_H
# define PARSE_CMDS_H

# include "msh_commons.h"

# define EXPECTED_CHAR_ERROR	"minishell: unexpected EOF while looking for \
matching `%c'\nminishell: syntax error: unexpected end of file\n"
# define QUOTES					"\"'"
# define SEPARATORS				" \"'<|>"
# define UNEXPECTED_EOF_ERROR	"minishell: syntax error: unexpected end of \
file\n"

bool	expand_env(char **str, char **envp);
bool	join_quotes(char **strs);
bool	msh_split(char *str, char ***strs);
void	remove_quotes(char **strs);
void	remove_spaces(char **strs);
void	shift_strs(char **strs);
bool	sign_quotes(char *str);
void	unsign_strs(char **strs);

#endif
