/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:21:41 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/10 13:51:49 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_copy(va_list *ap, char *buffer)
{
	const char	*s;
	size_t		i;

	s = va_arg(*ap, const char *);
	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		buffer[i] = s[i];
		i++;
	}
}

size_t	s_size(va_list *ap)
{
	const char	*s;

	s = va_arg(*ap, const char *);
	if (!s)
		return (6);
	return (ft_strlen(s));
}
