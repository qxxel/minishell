/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:16:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/18 12:25:03 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

bool	expand_env_var(char *str)
{
	size_t	i;
	size_t	size;
	size_t	var_name_size;

	i = -1;
	size = 0;
	var_name_size = 0;
	while (str[++i])
	{
		if (str[i] == '$')
		{

		}
		else
			size++;
	}
}
