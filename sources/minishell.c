/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:04:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/19 17:49:18 by deydoux          ###   ########.fr       */
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
	if (dup_envp(envp, &msh))
		return (EXIT_FAILURE);
	printf("%s\n", get_env_var("PATH", 0, msh.envp));
	str = ft_strdup("echo \"Hello'\"'\"World' '' $USER | cat -e >> my_outfile \
| wc");
	parse_cmds(str, &msh);
	free(str);
	return (EXIT_SUCCESS);
}
