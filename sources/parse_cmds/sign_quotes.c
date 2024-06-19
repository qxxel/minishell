/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:03:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/19 13:04:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	sign_quotes(char *str, char quote_type)
{
	char	quote;
	size_t	i;

	quote = 0;
	i = -1;
	while (str[++i])
	{
		if (quote)
		{
			if (str[i] == quote)
				quote = 0;
			else if (quote == quote_type)
				str[i] *= -1;
		}
		else if (ft_strchr(QUOTES, str[i]))
			quote = str[i];
	}
	if (quote)
	{
		ft_dprintf(STDERR_FILENO, EXPECTED_CHAR_ERROR, quote);
		return (true);
	}
	return (false);
}
