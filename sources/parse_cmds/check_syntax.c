/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:07:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/28 19:23:00 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static bool	check_redirects(char **strs)
{
	size_t	len;

	len = ft_strlen(strs[0]);
	if (len > 3)
		ft_dprintf(STDERR_FILENO, EXPECTED_CHARS_ERROR, strs[0][0], strs[0][1]);
	else if (len > 2)
		ft_dprintf(STDERR_FILENO, EXPECTED_CHAR_ERROR, strs[0][0]);
	else if (!strs[1])
		ft_dprintf(STDERR_FILENO, EXPECTED_STR_ERROR, "newline");
	else if (ft_strchr(SEPARATORS, strs[1][0]))
		ft_dprintf(STDERR_FILENO, EXPECTED_STR_ERROR, strs[1]);
	else
		return (false);
	return (true);
}

static bool	check_pipe(char **strs)
{
	if (strs[0][1] || !strs[1] || strs[1][0] == '|')
	{
		ft_dprintf(STDERR_FILENO, EXPECTED_CHAR_ERROR, '|');
		return (true);
	}
	return (false);
}

bool	check_syntax(char **strs)
{
	size_t	i;

	if (strs[0] && strs[0][0] == '|')
	{
		ft_dprintf(STDERR_FILENO, EXPECTED_CHAR_ERROR, '|');
		return (true);
	}
	i = 0;
	while (strs[i])
	{
		if (strs[i][0] == '<' || strs[i][0] == '>')
		{
			if (check_redirects(&strs[i]))
				return (true);
		}
		else if (strs[i][0] == '|')
			if (check_pipe(&strs[i]))
				return (true);
		i++;
	}
	return (false);
}
