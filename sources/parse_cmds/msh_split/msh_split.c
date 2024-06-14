/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:07:20 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/14 23:25:35 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_split.h"

bool	msh_split(char *str, char ***strs)
{
	char	quote;
	size_t	dst_i;
	size_t	i;
	size_t	strs_i;

	if (msh_split_init(str, 0, strs))
		return (true);
	i = 0;
	strs_i = -1;
	while (strs[++strs_i])
	{
		dst_i = 0;
		while (str[i] == ' ')
			i++;
		if (str[i] == '|')
		{
			(*strs)[strs_i][dst_i++] = str[i++];
			continue ;
		}
		while (str[i] && str[i] != ' ' && str[i] != '|')
		{
			if (str[i] == '\\')
				(*strs)[strs_i][dst_i++] = str[++i];
			else if (str[i] == '"' || str[i] == '\'')
			{
				quote = str[i++];
				while (str[i] != quote || str[i - 1] == '\\')
				{
					if (str[i] == quote)
						dst_i--;
					(*strs)[strs_i][dst_i++] = str[i++];
				}
			}
			else
				(*strs)[strs_i][dst_i++] = str[i++];
			i++;
		}
	}
	return (false);
}
