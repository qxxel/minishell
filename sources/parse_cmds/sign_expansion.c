/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:03:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/08 13:54:52 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static bool	sign_quotes(char *str)
{
	char	quote;
	size_t	i;

	quote = 0;
	i = 0;
	while (str[i])
	{
		if (quote)
		{
			if (str[i] == quote)
				quote = 0;
			else
				str[i] *= -1;
		}
		else if (ft_strchr(QUOTES, str[i]))
			quote = str[i];
		i++;
	}
	if (quote)
	{
		ft_dprintf(STDERR_FILENO, UNEXPECTED_EOF_ERROR, quote);
		return (true);
	}
	return (false);
}

static bool	sign_delimiter(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] == '<')
		{
			i += 2;
			while (str[i] == ' ')
				i++;
			while (str[i] && !ft_strchr(DELIMITER_SEPARATORS, str[i]))
			{
				if (str[i] > 0)
					str[i] *= -1;
				i++;
			}
		}
		else
			i++;
	}
	return (false);
}

bool	sign_expansion(char *str)
{
	return (sign_quotes(str) || sign_delimiter(str));
}
