/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:04:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/24 18:14:42 by agerbaud         ###   ########.fr       */
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
	{
		path = getcwd(NULL, 0);
		if (!path)
			return (ft_strdup(".$ "));
		prompt = ft_strjoin(path, "$ ");
		free(path);
		return (prompt);
	}
	return (ft_strjoin(path, "$ "));
}

static char	*readline_prompt(t_msh msh)
{
	char	*prompt;
	char	*str;

	prompt = generate_prompt(msh);
	if (!prompt)
		return (readline(".$ "));
	str = readline(prompt);
	free(prompt);
	return (str);
}

int	main(int argc, char **argv, char **envp)
{
	bool				status;
	char				*str;
	t_msh				msh;

	status = init_msh(envp, &msh);
	while (!status)
	{
		set_sig_prompt();
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
