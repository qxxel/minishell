/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:05:57 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/25 18:38:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "msh_commons.h"

# define EXPAND_SEPARATORS		"<|>"
# define INT_TO_STR_MAX_SIZE	12
# define SIGINT_CODE	130

bool	exec_cmds(t_msh *msh);
bool	init_msh(char **envp, t_msh *msh);
bool	parse_cmds(char *str, t_msh *msh);
void	print_banner(void);
char	*readline_prompt(t_msh msh);
void	safe_itoa(int n, char *str);

#endif
