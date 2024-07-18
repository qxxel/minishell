/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:00:42 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/18 18:11:49 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static bool	create_buffer(bool newline, size_t size, char **buffer)
{
	*buffer = malloc((size + newline + 1) * sizeof(char));
	if (!*buffer)
	{
		perror("malloc");
		return (true);
	}
	if (newline)
		(*buffer)[size] = '\n';
	(*buffer)[size + newline] = 0;
	return (false);
}

static bool	init_buffer(char **argv, bool newline, size_t size, char **buffer)
{
	bool	space;
	size_t	len;

	if (!argv[0])
		return (create_buffer(newline, size, buffer));
	space = false;
	len = ft_strlen(argv[0]);
	if (len == 2 && argv[0][0] == '-' && argv[0][1] == 'n')
	{
		newline = 0;
		len = 0;
	}
	else if (size)
		space = true;
	if (init_buffer(&argv[1], newline, size + len + space, buffer))
		return (true);
	while (len--)
		(*buffer)[size + len + space] = argv[0][len];
	if (space)
		(*buffer)[size] = ' ';
	return (false);
}

int	ft_echo(char **argv, t_msh *msh)
{
	bool	status;
	char	*buffer;

	if (init_buffer(&argv[1], true, 0, &buffer))
		return (EXIT_FAILURE);
	status = write(STDOUT_FILENO, buffer, ft_strlen(buffer)) < 0;
	if (status)
		write_error("echo");
	free(buffer);
	return (status);
	(void)msh;
}
