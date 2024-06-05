/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:05:12 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/10 13:51:49 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	itoa_size(unsigned int u)
{
	size_t	size;

	size = u == 0;
	while (u)
	{
		u /= 10;
		size++;
	}
	return (size);
}

void	u_copy(va_list *ap, char *buffer)
{
	unsigned int	u;
	size_t			size;

	u = va_arg(*ap, unsigned int);
	size = itoa_size(u);
	if (!u)
	{
		*buffer = '0';
		return ;
	}
	while (u)
	{
		buffer[--size] = ft_abs(u % 10) + '0';
		u /= 10;
	}
}

size_t	u_size(va_list *ap)
{
	unsigned int	u;

	u = va_arg(*ap, unsigned int);
	return (itoa_size(u));
}
