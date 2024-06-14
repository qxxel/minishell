/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:20:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/14 21:25:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_SPLIT_H
# define MSH_SPLIT_H

# include "msh_commons.h"

# define EXPECTED_CHAR_ERROR	"minishell: unexpected EOF while looking for \
matching `%c'\nminishell: syntax error: unexpected end of file\n"
# define UNEXPECTED_EOF_ERROR	"minishell: syntax error: unexpected end of \
file\n"

bool	msh_split_init(char *str, size_t n, char ***strs);
bool	msh_split_len(char *str, size_t *i, size_t *len);

#endif
