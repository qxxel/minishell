/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:55:50 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/08 14:53:20 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmds.h"

static bool	create_redirects(char **strs, t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (strs[i] && strs[i][0] != '|')
	{
		if (strs[i][0] == '<' || strs[i][0] == '>')
			cmd->n_redirects++;
		i++;
	}
	if (!cmd->n_redirects)
		return (false);
	cmd->redirects = ft_calloc(cmd->n_redirects,
			sizeof(*cmd->redirects));
	if (!cmd->redirects)
	{
		perror("malloc");
		return (true);
	}
	return (false);
}

static void	update_delimiter(t_redirect *redirect)
{
	size_t	i;
	size_t	shift;

	if (redirect->out || !redirect->option)
		return ;
	i = 0;
	shift = 0;
	while (redirect->path[i + shift])
	{
		if (ft_strchr(QUOTES, redirect->path[i + shift])
			|| (redirect->path[i + shift] == '$'
				&& ft_strchr(QUOTES, redirect->path[i + shift + 1])))
		{
			redirect->expand = false;
			shift++;
		}
		else
		{
			redirect->path[i] = redirect->path[i + shift];
			i++;
		}
	}
	redirect->path[i] = 0;
}

static bool	init_redirects(char **strs, t_cmd *cmd)
{
	size_t	i_redirect;
	size_t	i_str;

	if (create_redirects(strs, cmd))
		return (true);
	i_redirect = 0;
	i_str = 0;
	while (strs[i_str] && strs[i_str][0] != '|')
	{
		if (strs[i_str][0] != '<' && strs[i_str][0] != '>')
		{
			i_str++;
			continue ;
		}
		unsign_str(strs[i_str + 1]);
		cmd->redirects[i_redirect] = (t_redirect){.expand = true,
			.path = strs[i_str + 1], .out = strs[i_str][0] == '>',
			.option = strs[i_str][1] != 0};
		update_delimiter(&cmd->redirects[i_redirect++]);
		shift_strs(&strs[i_str], true);
		shift_strs(&strs[i_str], false);
	}
	return (false);
}

static bool	init_cmd(char **strs, t_cmd *cmd)
{
	size_t	i;

	if (init_redirects(strs, cmd))
		return (true);
	i = 0;
	while (strs[i] && strs[i][0] != '|')
		i++;
	cmd->argv = malloc((i + 1) * sizeof(*cmd->argv));
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
	msh->n_cmds = 1;
	i = 0;
	while (strs[i])
		msh->n_cmds += strs[i++][0] == '|';
	msh->cmds = ft_calloc(msh->n_cmds, sizeof(*msh->cmds));
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
