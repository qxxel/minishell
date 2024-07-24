/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_banner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:04:02 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/24 12:05:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "banner.h"
#include "minishell.h"

void	print_banner(void)
{
	if (SHOW_BANNER)
		write(STDERR_FILENO, BANNER, BANNER_SIZE);
}
