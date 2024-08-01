/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:02:24 by deydoux           #+#    #+#             */
/*   Updated: 2024/08/01 12:47:27 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_TYPES_H
# define MSH_TYPES_H

# include "msh_commons.h"

typedef struct s_redirect
{
	bool	expand;
	bool	option;
	bool	out;
	char	*path;
}	t_redirect;

typedef struct s_cmd
{
	char		**argv;
	size_t		n_redirects;
	t_redirect	*redirects;
}	t_cmd;

typedef struct s_msh
{
	char	**envp;
	char	**paths;
	char	*pwd;
	int		fd[2];
	pid_t	pid;
	size_t	n_cmds;
	t_cmd	*cmds;
	t_list	*declare;
}	t_msh;

#endif
