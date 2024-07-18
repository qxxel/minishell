/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:55:48 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/18 15:11:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_path(char *path1, char *path2)
{
	char	*path;
	size_t	size;

	size = ft_strlen(path1) + ft_strlen(path2) + 2;
	path = malloc(size * sizeof(*path));
	if (!path)
	{
		perror("malloc");
		return (NULL);
	}
	ft_strlcpy(path, path1, size);
	ft_strlcat(path, "/", size);
	ft_strlcat(path, path2, size);
	return (path);
}
