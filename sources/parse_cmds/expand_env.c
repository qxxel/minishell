/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:16:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/22 22:39:12 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static bool	init_expand(size_t size, char **expand)
{
	*expand = malloc((size + 1) * sizeof(**expand));
	if (!*expand)
	{
		perror("malloc");
		return (true);
	}
	(*expand)[size] = 0;
	return (false);
}

static size_t	expand_size(char *str, size_t *var_len, char **value,
	char **envp)
{
	*var_len = 0;
	if (str[0] == '$')
	{
		while (str[*var_len + 1]
			&& !ft_strchr(SEPARATORS"$", str[*var_len + 1]))
			(*var_len)++;
		if (!*var_len)
			return (1);
		*value = get_env_var(str + 1, *var_len, envp);
		if (!*value)
			return (0);
		return (ft_strlen(*value));
	}
	return (1);
}

static bool	create_expand(char *str, size_t size, char **envp, char **expand)
{
	char	*value;
	size_t	value_size;
	size_t	var_len;

	if (!*str)
		return (init_expand(size, expand));
	value_size = expand_size(str, &var_len, &value, envp);
	if (create_expand(str + var_len + 1, size + value_size, envp, expand))
		return (true);
	if (str[0] == '$')
	{
		if (!var_len)
			(*expand)[size] = '$';
		else if (value)
			while (value_size--)
				(*expand)[size + value_size] = value[value_size]
					* (-1 + (2 * (value[value_size] == ' ')));
	}
	else
		(*expand)[size] = *str;
	return (false);
}

bool	expand_env(char **str, char **envp)
{
	char	*expand;

	if (create_expand(*str, 0, envp, &expand))
		return (true);
	free(*str);
	*str = expand;
	return (false);
}
