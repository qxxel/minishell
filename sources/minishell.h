/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:05:57 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/19 17:41:22 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "msh_commons.h"

bool	dup_envp(char **src, t_msh *msh);
bool	parse_cmds(char *str, t_msh *msh);

#endif
