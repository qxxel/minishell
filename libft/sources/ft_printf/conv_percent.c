/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:18:47 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/10 13:51:25 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_copy(va_list *ap, char *buffer)
{
	(void)ap;
	*buffer = '%';
}

size_t	percent_size(va_list *ap)
{
	(void)ap;
	return (1);
}
