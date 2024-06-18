/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:04:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/18 12:09:49 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	msh_split(char *str, char ***strs);

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_msh	msh;

	(void)argc;
	(void)argv;
	ft_bzero(&msh, sizeof(msh));
	if (init_envp(envp, &msh))
		return (EXIT_FAILURE);
	str = ft_strdup("echo \"Hello\"'World' '' | cat -e >> my_outfile | wc");
	parse_cmds(str, NULL);
	free(str);
	return (EXIT_SUCCESS);
}
