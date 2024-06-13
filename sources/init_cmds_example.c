/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds_example.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:40:29 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/13 16:51:14 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Equivalent of parsing the following command
// ls -la | cat -e >> my_outfile | wc
t_cmd	*init_cmds_example(void)
{
	t_cmd	*cmds;

	cmds = ft_calloc(4, sizeof(t_cmd));
	cmds[0].argv = ft_calloc(3, sizeof(*cmds[0].argv));
	cmds[0].argv[0] = ft_strdup("ls");
	cmds[0].argv[1] = ft_strdup("-la");
	cmds[1].argv = ft_calloc(3, sizeof(*cmds[1].argv));
	cmds[1].argv[0] = ft_strdup("cat");
	cmds[1].argv[1] = ft_strdup("-e");
	cmds[1].out = ft_strdup("my_outfile");
	cmds[1].append = true;
	cmds[2].argv = ft_calloc(2, sizeof(*cmds[2].argv));
	cmds[2].argv[0] = ft_strdup("wc");
	return (cmds);
}
