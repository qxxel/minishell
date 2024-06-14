/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:24:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/14 21:32:31 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_split.h"

static bool	handle_backslash(char *str, size_t *i)
{
	if (!str[++*i])
	{
		ft_putstr_fd(UNEXPECTED_EOF_ERROR, STDERR_FILENO);
		return (true);
	}
	return (false);
}

static bool	handle_quotes(char *str, size_t *i, size_t *len)
{
	char	quote;

	quote = str[(*i)++];
	while (str[*i] != quote || str[*i - 1] == '\\')
	{
		if (!str[*i])
		{
			ft_dprintf(STDERR_FILENO, EXPECTED_CHAR_ERROR, quote);
			return (true);
		}
		*len += str[(*i)++] != quote;
	}
	(*len)--;
	return (false);
}

bool	msh_split_len(char *str, size_t *i, size_t *len)
{
	*len = str[*i] == '|';
	if (*len)
	{
		(*i)++;
		return (false);
	}
	while (str[*i] && str[*i] != ' ' && str[*i] != '|')
	{
		if (str[*i] == '\\')
		{
			if (handle_backslash(str, i))
				return (true);
		}
		else if (str[*i] == '"' || str[*i] == '\'')
		{
			if (handle_quotes(str, i, len))
				return (true);
		}
		(*len)++;
		(*i)++;
	}
	return (false);
}
