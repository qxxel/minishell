/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:02:24 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/07 14:25:34 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_TYPES_H
# define MSH_TYPES_H

# include "minishell.h"

typedef struct s_cmd
{
	char			**argv;
	char			*bin;
	char			*heredoc;
	char			*in;
	char			*out;
	int				append;
	struct s_cmd	*and;
	struct s_cmd	*cmds;
	struct s_cmd	*or;
}	t_cmd;

#endif
