/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:18:16 by agerbaud          #+#    #+#             */
/*   Updated: 2024/06/13 15:18:46 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*join_path(char *start, char *end)
{
	size_t	size;
	char	*path;

	size = ft_strlen(start) + ft_strlen(end) + 2;
	path = malloc(sizeof(char) * size);
	if (!path)
		return (NULL);
	ft_strlcpy(path, start, size);
	ft_strlcat(path, "/", size);
	ft_strlcat(path, end, size);
	return (path);
}

char	*get_path(char *command, char **paths)
{
	char	*path;

	if (!command)
		return (NULL);
	if (ft_strchr(command, '/'))
		return (ft_strdup(command));
	if (!paths)
		return (NULL);
	while (*paths)
	{
		path = join_path(*paths++, command);
		if (!path || access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}