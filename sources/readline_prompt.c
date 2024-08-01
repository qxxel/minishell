/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:54:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/08/01 12:48:19 by agerbaud         ###   ########.fr       */
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
			return (NULL);
		prompt = ft_strjoin(path, "$ ");
		free(path);
		return (prompt);
	}
	return (ft_strjoin(path, "$ "));
}

static void	handle_sigint(int sig)
{
	g_status = SIG_BASE_STATUS + sig;
	rl_replace_line("", 0);
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_on_new_line();
	rl_redisplay();
}

static void	set_sig(void)
{
	struct sigaction	act;

	act.sa_flags = SA_RESTART;
	act.sa_handler = &handle_sigint;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);
}

char	*readline_prompt(t_msh msh)
{
	char	*prompt;
	char	*prompt_ptr;
	char	*str;

	prompt = generate_prompt(msh);
	prompt_ptr = prompt;
	if (!prompt)
		prompt_ptr = ".$ ";
	set_sig();
	str = readline(prompt_ptr);
	ignore_sig(SIGINT);
	free(prompt);
	return (str);
}
