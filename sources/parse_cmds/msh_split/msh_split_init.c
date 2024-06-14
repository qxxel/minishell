/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:21:28 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/14 21:32:14 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_split.h"

static bool	init_strs(size_t len, char ***strs)
{
	*strs = ft_calloc(len + 1, sizeof(char *));
	if (!*strs)
	{
		perror("malloc");
		return (true);
	}
	return (false);
}

static bool	init_str(size_t len, size_t i, char ***strs)
{
	(*strs)[i] = ft_calloc(len + 1, sizeof(char));
	if (!(*strs)[i])
	{
		perror("malloc");
		while ((*strs)[++i])
			free((*strs)[i]);
		free(*strs);
		return (true);
	}
	return (false);
}

bool	msh_split_init(char *str, size_t n, char ***strs)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!str[i])
		return (init_strs(n, strs));
	return (msh_split_len(str, &i, &len)
		|| msh_split_init(&str[i], n + 1, strs)
		|| init_str(len, n, strs));
}
