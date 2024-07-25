/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:54:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/24 18:54:53 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*readline_prompt(t_msh msh)
{
	char	*prompt;
	char	*str;

	prompt = generate_prompt(msh);
	set_sig_prompt();
	if (!prompt)
		return (readline(".$ "));
	str = readline(prompt);
	free(prompt);
	return (str);
}
