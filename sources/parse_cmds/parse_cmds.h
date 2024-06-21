/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:33:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/21 17:00:36 by deydoux          ###   ########.fr       */
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
bool	expand_quotes(char **str, char **envp);
bool	join_strs(char **strs);
bool	msh_split(char *str, char ***strs);
void	shift_strs(char **strs);
bool	sign_quotes(char *str);
void	unsign_str(char *str);
bool	unsign_strs(char **strs);

#endif
