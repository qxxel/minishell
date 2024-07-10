/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:02:24 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/09 21:30:03 by deydoux          ###   ########.fr       */
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
	pid_t		pid;
}	t_cmd;

typedef struct s_msh
{
	char	**envp;
	char	*pwd;
	int		fd[2];
	int		status;
	size_t	n_cmds;
	t_cmd	*cmds;
	t_list	*declare;
}	t_msh;

#endif
