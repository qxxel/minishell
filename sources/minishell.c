/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:04:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/18 18:06:20 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_msh	msh;

	(void)argc;
	(void)argv;
	ft_bzero(&msh, sizeof(msh));
	if (init_env(envp, &msh))
		return (EXIT_FAILURE);
	printf("%s\n", get_env_var("PATH", 0, msh.env));
	str = ft_strdup("echo \"Hello\"'World' '' | cat -e >> my_outfile | wc");
	parse_cmds(str, NULL);
	free(str);
	return (EXIT_SUCCESS);
}
