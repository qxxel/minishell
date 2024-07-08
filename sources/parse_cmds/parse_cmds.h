/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:33:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/08 14:40:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_CMDS_H
# define PARSE_CMDS_H

# include "msh_commons.h"

# define DELIMITER_SEPARATORS	" <|>"
# define EXPECTED_CHAR_ERROR	"minishell: syntax error near unexpected token \
`%c'\n"
# define EXPECTED_CHARS_ERROR	"minishell: syntax error near unexpected token \
`%c%c'\n"
# define EXPECTED_STR_ERROR		"minishell: syntax error near unexpected token \
`%s'\n"
# define QUOTES					"\"'"
# define SEPARATORS				" \"'<|>"
# define UNEXPECTED_EOF_ERROR	"minishell: unexpected EOF while looking for \
matching `%c'\nminishell: syntax error: unexpected end of file\n"

bool	check_syntax(char **strs);
bool	expand_quotes(char **str, char **envp);
bool	init_cmds(char **strs, t_msh *msh);
bool	join_strs(char **strs);
bool	msh_split(char *str, char ***strs);
bool	sign_expansion(char *str);
void	unsign_str(char *str);

#endif
