/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:04:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/09 16:39:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	bool	status;
	char	*str;
	t_msh	msh;

	status = init_msh(envp, &msh);
	while (!status)
	{
		str = readline("$ ");
		add_history(str);
		parse_cmds(str, &msh);
		status = exec_cmds(&msh);
		free_cmds(msh.cmds, msh.n_cmds);
	}
	destroy_msh(msh);
	return (status);
	(void)argc;
	(void)argv;
}
