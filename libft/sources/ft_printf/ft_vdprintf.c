/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:01:03 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/11 10:22:07 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_copy(
	const char specifier, va_list *ap, va_list *aq, t_conv_copy *copy)
{
	const char			*specifiers = "cdisu%";
	const t_conv_copy	conv_copy[] = {c_copy, d_copy, d_copy, s_copy,
		u_copy, percent_copy};
	const t_conv_size	conv_size[] = {c_size, d_size, d_size, s_size,
		u_size, percent_size};
	size_t				i;

	i = 0;
	while (specifiers[i])
	{
		if (specifiers[i] == specifier)
		{
			*copy = conv_copy[i];
			va_copy(*aq, *ap);
			return (conv_size[i](ap));
		}
		i++;
	}
	return (1);
}

static char	*create_buffer(const char *format, va_list *ap, size_t *size)
{
	t_conv_copy	copy;
	size_t		i;
	va_list		aq;
	char		*buffer;

	if (!*format)
		return (malloc(sizeof(char) * *size));
	copy = NULL;
	i = *size;
	if (*format == '%')
		*size += get_copy(format[1], ap, &aq, &copy);
	else
		(*size)++;
	buffer = create_buffer(format + 1 + (copy != NULL), ap, size);
	if (buffer)
	{
		if (!copy)
			buffer[i] = *format;
		else
			copy(&aq, buffer + i);
	}
	if (copy)
		va_end(aq);
	return (buffer);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	va_list	aq;
	size_t	size;
	char	*buffer;
	ssize_t	len;

	if (!format)
		return (-1);
	va_copy(aq, ap);
	size = 0;
	buffer = create_buffer(format, &aq, &size);
	va_end(aq);
	if (!buffer)
		return (-1);
	len = write(fd, buffer, size);
	free(buffer);
	return (len);
}
