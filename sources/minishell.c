/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:04:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/24 14:17:24 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;

static char	*generate_prompt(t_msh msh)
{
	char	*path;
	char	*prompt;

	if (msh.pwd)
		path = msh.pwd;
	else
		path = get_env_var("PWD", 3, msh.envp);
	if (!path)
		path = ".";
	prompt = ft_strjoin(path, "$ ");
	return (prompt);
}

static char	*readline_prompt(t_msh msh)
{
	char	*prompt;
	char	*str;

	prompt = generate_prompt(msh);
	if (!prompt)
		return (readline("$ "));
	str = readline(prompt);
	free(prompt);
	return (str);
}

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
