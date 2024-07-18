/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:29:03 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/18 16:21:13 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static bool	create_expand(char **str, size_t start, char *files, size_t end)
{
	char	*expand;
	size_t	size;

	size = start + ft_strlen(files) + ft_strlen(&(*str)[end]) + 1;
	expand = malloc(size * sizeof(*expand));
	if (!expand)
	{
		perror("malloc");
		free(files);
		return (true);
	}
	ft_strlcpy(expand, *str, start + 1);
	ft_strlcat(expand, files, size);
	ft_strlcat(expand, &(*str)[end], size);
	free(files);
	free(*str);
	*str = expand;
	return (false);
}

static bool	expand_wildcard(char **str, size_t wildcard)
{
	char	*files;
	char	end_char;
	size_t	end;
	size_t	start;

	start = wildcard;
	while (start && !ft_strchr(DELIMITER_SEPARATORS, (*str)[start - 1]))
		start--;
	end = wildcard;
	while ((*str)[end] && !ft_strchr(DELIMITER_SEPARATORS, (*str)[end]))
		end++;
	end_char = (*str)[end];
	(*str)[end] = 0;
	if (compute_wildcard(&(*str)[start], &files))
		return (true);
	(*str)[end] = end_char;
	return (create_expand(str, start, files, end));
}

bool	expand_wildcards(char **str)
{
	char	*wildcard_ptr;

	wildcard_ptr = ft_strchr(*str, '*');
	while (wildcard_ptr)
	{
		if (expand_wildcard(str, wildcard_ptr - *str))
			return (true);
		wildcard_ptr = ft_strchr(*str, '*');
	}
	return (false);
}
