/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:54:03 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/10 13:51:49 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_copy(va_list *ap, char *buffer)
{
	*buffer = va_arg(*ap, int);
}

size_t	c_size(va_list *ap)
{
	va_arg(*ap, int);
	return (1);
}
