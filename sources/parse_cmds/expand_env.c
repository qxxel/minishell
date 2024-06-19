/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:16:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/19 17:47:16 by deydoux          ###   ########.fr       */
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

static size_t	var_size(char *str, size_t *start, char **envp)
{
	char	*value;
	size_t	var_len;

	var_len = get_var_len(str);
	*start += var_len;
	if (!var_len)
		return (1);
	value = get_env_var(str, var_len, envp);
	if (!value)
		return (0);
	return (ft_strlen(value));
}

static size_t	new_str_size(char *str, char **envp)
{
	size_t	i;
	size_t	size;

	i = -1;
	size = 0;
	while (str[++i])
	{
		ft_putchar_fd(str[i], 1);
		if (str[i] == '$')
			size += var_size(&str[i + 1], &i, envp);
		else
			size++;
	}
	return (size);
}

bool	expand_env(char **str, char **envp)
{
	printf("%zu %zu\n", ft_strlen(*str), new_str_size(*str, envp));
	return (false);
}
