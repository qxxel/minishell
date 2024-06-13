/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:33:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/12 15:37:27 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_CMDS_H
# define PARSE_CMDS_H

# include "msh_commons.h"

# define EXPECTED_CHAR_ERROR	"minishell: unexpected EOF while looking for \
matching `%c'\nminishell: syntax error: unexpected end of file\n"
# define UNEXPECTED_EOF_ERROR	"minishell: syntax error: unexpected end of \
file\n"

#endif
