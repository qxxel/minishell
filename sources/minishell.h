/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:05:57 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/09 14:38:02 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "msh_commons.h"

void	destroy_msh(t_msh msh);
bool	exec_cmds(t_msh *msh);
void	free_cmds(t_cmd *cmds, size_t n);
bool	init_msh(char **envp, t_msh *msh);
bool	parse_cmds(char *str, t_msh *msh);

#endif
