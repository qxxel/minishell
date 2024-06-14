/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:04:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/14 20:10:25 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	msh_split(char *str, char ***strs);

int	main(int argc, char **argv, char **envp)
{
	char	*str = "ls '-la u'\"uwu   \\\"eheheheh       \"| cat -e >> my_outfile | wc\\";
	char	**strs;
	size_t	i;

	(void)argc;
	(void)argv;
	(void)envp;
	if (msh_split(str, &strs))
		return (EXIT_FAILURE);
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (EXIT_SUCCESS);
}
