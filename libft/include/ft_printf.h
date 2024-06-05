/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:10:20 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/10 13:52:04 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <limits.h>

typedef void	(*t_conv_copy)(va_list *, char *);
typedef size_t	(*t_conv_size)(va_list *);

void	c_copy(va_list *ap, char *buffer);
size_t	c_size(va_list *ap);
void	d_copy(va_list *ap, char *buffer);
size_t	d_size(va_list *ap);
void	percent_copy(va_list *ap, char *buffer);
size_t	percent_size(va_list *ap);
void	s_copy(va_list *ap, char *buffer);
size_t	s_size(va_list *ap);
void	u_copy(va_list *ap, char *buffer);
size_t	u_size(va_list *ap);

#endif
