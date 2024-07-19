/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:16:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/19 18:12:02 by deydoux          ###   ########.fr       */
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

static size_t	expand_size(char *str, size_t *id_len, char **value, t_msh msh)
{
	*id_len = 0;
	if (str[0] != '$')
		return (1);
	if (str[1] == '?' || ft_isdigit(str[1]))
		(*id_len)++;
	else
		while (str[*id_len + 1]
			&& (ft_isalnum(str[*id_len + 1]) || str[*id_len + 1] == '_'))
			(*id_len)++;
	if (!*id_len)
		return (1);
	if (str[1] == '?')
		safe_itoa(msh.status, *value);
	else
		*value = get_env_var(str + 1, *id_len, msh.envp);
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

static bool	create_expand(char *str, size_t size, t_msh msh, char **expand)
{
	char	*value;
	char	status[INT_TO_STR_MAX_SIZE];
	size_t	id_len;
	size_t	value_len;

	if (!*str)
		return (init_expand(size, expand));
	value = status;
	value_len = expand_size(str, &id_len, &value, msh);
	if (create_expand(&str[id_len + 1], size + value_len, msh, expand))
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

bool	expand_env(char **str, t_msh msh)
{
	char	*expand;

	if (create_expand(*str, 0, msh, &expand))
		return (true);
	free(*str);
	*str = expand;
	return (false);
}
