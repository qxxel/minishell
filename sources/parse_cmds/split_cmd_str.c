/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:07:20 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/14 20:03:34 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static bool	init_strs(char *str, size_t n_str, char ***strs)
{
	char	quote;
	size_t	len;

	while (*str == ' ')
		str++;
	if (!*str)
	{
		*strs = ft_calloc(n_str + 1, sizeof(char *));
		if (!*strs)
		{
			perror("malloc");
			return (true);
		}
		return (false);
	}
	len = *str == '|';
	if (len)
		str++;
	else
	{
		while (*str && *str != ' ' && *str != '|')
		{
			if (*str == '\\')
			{
				if (!*(++str))
				{
					ft_putstr_fd(UNEXPECTED_EOF_ERROR, STDERR_FILENO);
					return (true);
				}
				len++;
			}
			else if (*str == '"' || *str == '\'')
			{
				quote = *(str++);
				while (*str != quote || *(str - 1) == '\\')
				{
					if (!*(str++))
					{
						ft_dprintf(STDERR_FILENO, EXPECTED_CHAR_ERROR, quote);
						return (true);
					}
					len++;
				}
			}
			else
				len++;
			str++;
		}
		printf("str[%zu] + \"%s\"\n", len, str);
	}
	if (init_strs(str, n_str + 1, strs))
		return (true);
	(*strs)[n_str] = ft_calloc(len + 1, sizeof(char));
	if (!(*strs)[n_str])
	{
		perror("malloc");
		return (true);
	}
	return (false);
}

bool	split_cmd_str(char *str, char ***strs)
{
	return (init_strs(str, 0, strs));
}
