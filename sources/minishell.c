/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:04:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/25 15:47:21 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;

int	main(int argc, char **argv, char **envp)
{
	bool	status;
	char	*str;
	t_msh	msh;

	status = init_msh(envp, &msh);
	while (!status)
	{
		str = readline_prompt(msh);
		set_sig_exec();
		if (!str)
		{
			ft_putstr_fd("exit\n", STDERR_FILENO);
			break ;
		}
		add_history(str);
		if (!parse_cmds(str, &msh))
			status = exec_cmds(&msh);
		free_cmds(msh.cmds, msh.n_cmds);
		msh.cmds = NULL;
		msh.n_cmds = 0;
	}
	destroy_msh(msh);
	return (status);
	(void)argc;
	(void)argv;
}
