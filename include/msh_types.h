/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:02:24 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/24 16:45:19 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_TYPES_H
# define MSH_TYPES_H

# include "msh_commons.h"

typedef struct s_redirect
{
	bool	option;
	bool	out;
	char	*name;
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
	size_t	envc;
	size_t	n_cmds;
	t_cmd	*cmds;
}	t_msh;

#endif
