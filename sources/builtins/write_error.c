/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:58:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/18 17:59:55 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	write_error(char *program)
{
	ft_dprintf(STDERR_FILENO, WRITE_ERROR, program, strerror(errno));
	return (true);
}
