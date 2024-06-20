/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:16:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/20 14:32:36 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static size_t	get_var_len(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && !ft_strchr(SEPARATORS, str[len]))
		len++;
	return (len);
}

static size_t	value_len(char *str, size_t *i, char **envp)
{
	char	*value;
	size_t	var_len;

	var_len = get_var_len(str);
	*i += var_len;
	if (!var_len)
		return (1);
	value = get_env_var(str, var_len, envp);
	if (!value)
		return (0);
	return (ft_strlen(value));
}

static size_t	expand_size(char *str, char **envp)
{
	size_t	i;
	size_t	size;

	i = -1;
	size = 0;
	while (str[++i])
	{
		if (str[i] == '$')
			size += value_len(&str[i + 1], &i, envp);
		else
			size++;
	}
	return (size);
}

static void	copy_expand(char *src, char *dst, char **envp)
{
	char	*value;
	size_t	i_dst;
	size_t	i_src;
	size_t	var_len;

	i_src = -1;
	i_dst = 0;
	while (src[++i_src])
	{
		if (src[i_src] == '$')
		{
			var_len = get_var_len(&src[i_src + 1]);
			if (!var_len)
				dst[i_dst++] = '$';
			else
			{
				value = get_env_var(&src[i_src + 1], var_len, envp);
				if (*value)
					while (*value)
						dst[i_dst++] = *value++;
				i_src += var_len;
			}
		}
		else
			dst[i_dst++] = src[i_src];
	}
	dst[i_dst] = 0;
}

bool	expand_env(char **str, char **envp)
{
	char	*expand;

	expand = malloc((expand_size(*str, envp) + 1) * sizeof(char));
	if (!expand)
	{
		perror("malloc");
		return (true);
	}
	copy_expand(*str, expand, envp);
	printf("EXPAND_ENV:\n%s\n%s\n", *str, expand);
	free(*str);
	*str = expand;
	return (false);
}
