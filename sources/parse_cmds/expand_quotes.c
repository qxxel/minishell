/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:18:31 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/08 12:35:50 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static void	sign_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 0)
			str[i] *= -1;
		i++;
	}
}

static void	remove_quotes(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		if (ft_strchr(QUOTES, strs[i][0]))
			shift_strs(&strs[i], true);
		else
			i++;
	}
}

bool	expand_quotes(char **strs, char **envp)
{
	bool	even_quotes;
	size_t	i;

	even_quotes = true;
	i = 0;
	while (strs[i])
	{
		if (strs[i][0] == '"' && ft_strlen(strs[i]) % 2 == even_quotes)
		{
			even_quotes = !even_quotes;
			shift_strs(&strs[i], true);
			unsign_str(strs[i]);
			if (expand_env(&strs[i], envp))
				return (true);
			sign_str(strs[i]);
		}
		else
			even_quotes = true;
		i++;
	}
	remove_quotes(strs);
	return (false);
}
