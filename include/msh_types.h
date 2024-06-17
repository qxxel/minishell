/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:02:24 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/17 17:43:20 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_TYPES_H
# define MSH_TYPES_H

# include "msh_commons.h"

typedef struct s_cmd
{
	bool	append;
	char	**argv;
	char	*heredoc;
	char	*in;
	char	*out;
}	t_cmd;

typedef struct s_msh_envp
{
	char				*key;
	char				*val;
	struct s_msh_envp	*next;
}	t_msh_envp;

typedef struct s_msh
{
	t_msh_envp	*envp;
}	t_msh;


#endif
