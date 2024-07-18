/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:16:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/18 14:26:52 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static size_t	expand_size(char *str, size_t *id_len, char **value,
	char **envp)
{
	*id_len = 0;
	if (str[0] != '$')
		return (1);
	if (ft_isdigit(str[1]))
		(*id_len)++;
	else
		while (str[*id_len + 1]
			&& (ft_isalnum(str[*id_len + 1]) || str[*id_len + 1] == '_'))
			(*id_len)++;
	if (!*id_len)
		return (1);
	*value = get_env_var(str + 1, *id_len, envp);
	if (!*value)
		return (0);
	return (ft_strlen(*value));
}

static char	sign_expand(char c)
{
	if (ft_strchr(EXPAND_SEPARATORS, c))
		return (c * -1);
	return (c);
}

static bool	create_expand(char *str, size_t size, char **envp, char **expand)
{
	char	*value;
	size_t	id_len;
	size_t	value_len;

	if (!*str)
		return (init_expand(size, expand));
	value_len = expand_size(str, &id_len, &value, envp);
	if (create_expand(&str[id_len + 1], size + value_len, envp, expand))
		return (true);
	if (str[0] == '$')
	{
		if (!id_len)
			(*expand)[size] = '$';
		else if (value)
			while (value_len--)
				(*expand)[size + value_len] = sign_expand(value[value_len]);
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
