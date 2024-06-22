/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:55:50 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/22 21:33:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static bool	create_redirection(char **strs, t_cmd *cmd)
{
	size_t	i;

	i = -1;
	while (strs[++i] && strs[i][0] != '|')
		if (strs[i][0] == '<' || strs[i][0] == '>')
			cmd->n_redirection++;
	if (!cmd->n_redirection)
		return (false);
	cmd->redirections = ft_calloc(cmd->n_redirection,
			sizeof(*cmd->redirections));
	if (!cmd->redirections)
	{
		perror("malloc");
		return (true);
	}
	return (false);
}

static bool	init_redirections(char **strs, t_cmd *cmd)
{
	size_t	i_redirection;
	size_t	i_strs;

	if (create_redirection(strs, cmd))
		return (true);
	i_redirection = 0;
	i_strs = -1;
	while (strs[++i_strs] && strs[i_strs][0] != '|')
	{
		if (strs[i_strs][0] != '<' && strs[i_strs][0] != '>')
			continue ;
		unsign_str(strs[i_strs + 1]);
		cmd->redirections[i_redirection++] = (t_redirction){
			.name = strs[i_strs + 1],
			.out = strs[i_strs][0] == '>',
			.option = strs[i_strs][1] != 0
		};
		shift_strs(&strs[i_strs], true);
		shift_strs(&strs[i_strs], false);
	}
	return (false);
}

static bool	init_cmd(char **strs, t_cmd *cmd)
{
	size_t	i;

	if (init_redirections(strs, cmd))
		return (true);
	i = 0;
	while (strs[i] && strs[i][0] != '|')
		i++;
	cmd->argv = malloc((i + 1) * sizeof(char));
	if (!cmd->argv)
	{
		perror("malloc");
		return (true);
	}
	cmd->argv[i] = NULL;
	i = 0;
	while (strs[0] && strs[0][0] != '|')
	{
		unsign_str(strs[0]);
		cmd->argv[i++] = strs[0];
		shift_strs(strs, false);
	}
	shift_strs(strs, true);
	return (false);
}

bool	init_cmds(char **strs, t_msh *msh)
{
	size_t	i;

	if (!strs[0])
		return (false);
	msh->n_cmd = 1;
	i = -1;
	while (strs[++i])
		msh->n_cmd += strs[i][0] == '|';
	msh->cmds = ft_calloc(msh->n_cmd, sizeof(*msh->cmds));
	if (!msh->cmds)
	{
		perror("malloc");
		return (true);
	}
	i = 0;
	while (strs[0])
		if (init_cmd(strs, &msh->cmds[i++]))
			return (true);
	return (false);
}
