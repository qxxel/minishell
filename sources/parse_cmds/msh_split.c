/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:41:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/23 13:35:39 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static size_t	strs_len(char *str)
{
	char	separator;
	size_t	i;
	size_t	size;

	separator = str[0] * (ft_strchr(SEPARATORS, str[0]) != 0);
	i = 0;
	size = 2;
	while (str[i])
	{
		if (ft_strchr(SEPARATORS, str[i]))
		{
			size += str[i] != separator;
			separator = str[i];
		}
		else
		{
			size += separator != 0;
			separator = 0;
		}
		i++;
	}
	return (size);
}

static bool	init_strs(char *str, char ***strs)
{
	*strs = ft_calloc(strs_len(str), sizeof(**strs));
	if (!*strs)
	{
		perror("malloc");
		return (true);
	}
	return (false);
}

static bool	segment_str(char *str, char **strs, size_t *start, size_t end)
{
	static size_t	i = 0;

	if (!*start)
		i = 0;
	strs[i] = ft_substr(&str[*start], 0, end - *start);
	if (!strs[i++])
	{
		perror("malloc");
		free_nptr(2, strs);
		return (true);
	}
	*start = end;
	return (false);
}

bool	msh_split(char *str, char ***strs)
{
	char	separator;
	size_t	end;
	size_t	start;

	if (init_strs(str, strs))
		return (true);
	separator = str[0] * (ft_strchr(SEPARATORS, str[0]) != 0);
	end = -1;
	start = 0;
	while (str[++end])
	{
		if (ft_strchr(SEPARATORS, str[end]))
		{
			if (str[end] != separator && segment_str(str, *strs, &start, end))
				return (true);
			separator = str[end];
		}
		else
		{
			if (separator && segment_str(str, *strs, &start, end))
				return (true);
			separator = 0;
		}
	}
	return (segment_str(str, *strs, &start, end));
}
