/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:38:22 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/11 15:12:01 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static bool	check_quote(char *str)
{
	size_t	i;
	char	quote;

	i = 0;
	while (str[i])
	{
		quote = str[i++];
		if (ft_strchr("\"\'", quote) && !ft_strchr(&str[i], quote))
		{

		}
	}
}

bool	check_syntax(char *str)
{

}
