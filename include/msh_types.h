/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:02:24 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/18 15:56:45 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_TYPES_H
# define MSH_TYPES_H

# include "msh_commons.h"

typedef struct s_redirection
{
	bool	option;
	bool	out;
	char	*name;
}	t_redirction;

typedef struct s_cmd
{
	char			**argv;
	t_redirction	*redirections;
}	t_cmd;

typedef struct s_msh
{
	t_list	*envp;
}	t_msh;

#endif
