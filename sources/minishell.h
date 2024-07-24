/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:05:57 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/24 18:39:49 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "msh_commons.h"

# define EXPAND_SEPARATORS		"<|>"
# define INT_TO_STR_MAX_SIZE	12
# define INT_TO_STR_MAX_SIZE	12
# define SIGINT_CODE            130
# define SIGQUIT_MESSAGE	    "Quit (core dumped)\n"

bool	exec_cmds(t_msh *msh);
bool	init_msh(char **envp, t_msh *msh);
bool	parse_cmds(char *str, t_msh *msh);
void	print_banner(void);
void	safe_itoa(int n, char *str);

#endif
