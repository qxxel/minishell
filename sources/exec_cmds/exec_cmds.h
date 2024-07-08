/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:44:17 by agerbaud          #+#    #+#             */
/*   Updated: 2024/07/08 18:39:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CMDS_H
# define EXEC_CMDS_H

# include "msh_commons.h"

# define FILE_ERROR			"minishell: %s: %s\n"
# define REDIRECT_OPEN_MODE	0666

typedef struct s_exec_fd
{
	int	in;
	int	pipe[2];
}	t_exec_fd;

typedef int	(*t_builtin)(char **, t_msh *);

typedef enum e_redirect_flag
{
	append_out_flag = O_WRONLY | O_CREAT | O_APPEND,
	redirect_in_flag = O_RDONLY,
	redirect_out_flag = O_WRONLY | O_CREAT | O_TRUNC
}	t_redirect_flag;

t_builtin	get_builtin(char *name);
char		*get_path(char *command, char **paths);
void		init_redirects(t_cmd cmd);
void		safe_dup2(int new_fd, int old_fd);

#endif
