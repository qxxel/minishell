/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:04:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/08/01 12:34:56 by agerbaud         ###   ########.fr       */
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
		if (!str)
		{
			ft_putstr_fd("exit\n", STDERR_FILENO);
			break ;
		}
		if (str[0])
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
