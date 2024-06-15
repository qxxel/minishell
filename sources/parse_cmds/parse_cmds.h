/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:33:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/15 17:42:23 by deydoux          ###   ########.fr       */
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

bool	mark_quotes(char *str);
bool	msh_split(char *str, char ***strs);

#endif
