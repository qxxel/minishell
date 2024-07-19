/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wildcard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:42:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/19 16:01:24 by deydoux          ###   ########.fr       */
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

static char	*strstr_pattern(char *name, char *pattern)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (name[i])
	{
		j = 0;
		while (pattern[j] && pattern[j] != '*' && name[i + j] == pattern[j])
			j++;
		if (!pattern[j] || pattern[j] == '*')
			return (&name[i]);
		i++;
	}
	return (NULL);
}

static bool	match_pattern(char *name, char *pattern)
{
	if (name[0] == '.' && (pattern[0] != '.' || !name[1]
			|| (name[1] == '.' && !name[2])))
		return (false);
	while (pattern[0])
	{
		while (pattern[0] == '*' && pattern[1] == '*')
			pattern++;
		if (pattern[0] == '*')
		{
			if (!pattern[1])
				return (true);
			pattern++;
		}
		name = strstr_pattern(name, pattern);
		if (!name)
			return (false);
		if (!ft_strcmp(name, pattern))
			return (true);
		while (pattern[0] && pattern[0] != '*')
			pattern++;
	}
	return (false);
}

static bool	create_files(char *pattern, DIR *dir, size_t size, char **files)
{
	size_t			len;
	struct dirent	*entry;

	entry = readdir(dir);
	if (!entry)
		return (init_files(size, files, pattern));
	len = 0;
	if (!match_pattern(entry->d_name, pattern))
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
