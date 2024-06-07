/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:02:24 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/07 15:23:20 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_TYPES_H
# define MSH_TYPES_H

# include "minishell.h"

typedef struct s_cmd
{
	char			**argv;
	char			*heredoc;
	char			*in;
	char			*out;
	int				append;
	struct s_cmd	*and;
	struct s_cmd	*cmds;
	struct s_cmd	*or;
	struct s_cmd	*pipe;
}	t_cmd;

#endif
