/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:11:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/19 18:12:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	safe_itoa(int n, char *str)
{
	int		tmp_n;
	size_t	len;

	tmp_n = n;
	len = n <= 0;
	while (tmp_n)
	{
		tmp_n /= 10;
		len++;
	}
	str[len--] = 0;
	if (n < 0)
		str[0] = '-';
	else
		str[0] = '0';
	while (n)
	{
		str[len--] = ft_abs(n % 10) + '0';
		n /= 10;
	}
}
