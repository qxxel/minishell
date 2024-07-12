/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:44:17 by agerbaud          #+#    #+#             */
/*   Updated: 2024/07/12 14:34:47 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CMDS_H
# define EXEC_CMDS_H

# include "msh_commons.h"

# define CMD_ENOENT_ERROR		"%s: command not found\n"
# define DELIMITER_WARNING		"minishell: warning: here-document at line %d \
delimited by end-of-file (wanted `%s')\n"
# define EACCES_EXIT_CODE		126
# define ENOENT_EXIT_CODE		127
# define FILE_ERROR				"minishell: %s: %s\n"
# define REDIRECT_OPEN_MODE		0666

typedef struct s_exec_fd
{
	int	in;
	int	pipe[2];
}	t_exec_fd;

typedef struct s_exec_context
{
	char	**argv;
	char	**envp;
	char	*bin;
}	t_exec_context;

typedef int	(*t_builtin)(char **, t_msh *);

typedef enum e_redirect_flag
{
	append_out_flag = O_WRONLY | O_CREAT | O_APPEND,
	redirect_in_flag = O_RDONLY,
	redirect_out_flag = O_WRONLY | O_CREAT | O_TRUNC
}	t_redirect_flag;

void		exec_bin(t_cmd *cmd, t_msh *msh);
bool		exec_cmd(t_cmd *cmd, bool last, t_exec_fd *fd, t_msh *msh);
t_builtin	get_builtin(char *name);
void		init_redirects(t_cmd cmd, char **envp);
void		safe_dup2(int new_fd, int old_fd);

#endif
