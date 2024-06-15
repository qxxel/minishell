/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:04:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/15 17:54:31 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	msh_split(char *str, char ***strs);

int	main(int argc, char **argv, char **envp)
{
	char	**strs;
	char	*str;
	size_t	i;

	(void)argc;
	(void)argv;
	(void)envp;
	str = ft_strdup("echo \"Hello\"'World' '' | cat -e >> my_outfile | wc");
	if (msh_split(str, &strs))
		return (EXIT_FAILURE);
	free(str);
	i = -1;
	while (strs[++i])
	{
		printf("%s\n", strs[i]);
		free(strs[i]);
	}
	free(strs);
	return (EXIT_SUCCESS);
}
