/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wildcard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:42:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/18 17:32:03 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static bool	init_files(size_t size, char **files, char *pattern)
{
	if (!size)
		*files = ft_strdup(pattern);
	else
		*files = malloc((size + 1) * sizeof(**files));
	if (!*files)
	{
		perror("malloc");
		return (true);
	}
	if (size)
		(*files)[size] = 0;
	else
		while ((*files)[size])
			(*files)[size++] *= -1;
	return (false);
}

static bool	match_name(char *name, char *pattern)
{
	(void)name;
	(void)pattern;
	return (true);
}

static bool	create_files(char *pattern, DIR *dir, size_t size, char **files)
{
	size_t			len;
	struct dirent	*entry;

	entry = readdir(dir);
	if (!entry)
		return (init_files(size, files, pattern));
	len = 0;
	if (!match_name(entry->d_name, pattern))
		entry = NULL;
	else
		len = ft_strlen(entry->d_name);
	if (create_files(pattern, dir, size + len + (entry != NULL), files))
		return (true);
	if (!entry)
		return (false);
	(*files)[size + len] = ' ';
	while (len--)
		(*files)[size + len] = entry->d_name[len] * -1;
	return (false);
}

bool	compute_wildcard(char *pattern, char **files)
{
	bool	status;
	DIR		*dir;

	dir = opendir(".");
	if (!dir)
	{
		perror("opendir");
		return (true);
	}
	status = create_files(pattern, dir, 0, files);
	closedir(dir);
	return (status);
}
