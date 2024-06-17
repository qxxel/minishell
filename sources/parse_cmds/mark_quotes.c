/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:03:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/17 12:35:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	mark_quotes(char *str)
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
			else
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
