/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_commons.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:17:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/08/01 12:54:36 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_COMMONS_H
# define MSH_COMMONS_H

# define _GNU_SOURCE
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# include "libft.h"
# include "msh_types.h"

# define SIG_BASE_STATUS	128

extern int	g_status;

void	destroy_msh(t_msh msh);
bool	expand_env(char **str, char **envp);
void	free_cmds(t_cmd *cmds, size_t n);
int		ft_cd(char **argv, t_msh *msh);
int		ft_echo(char **argv, t_msh *msh);
int		ft_env(char **argv, t_msh *msh);
int		ft_exit(char **argv, t_msh *msh);
int		ft_export(char **argv, t_msh *msh);
int		ft_pwd(char **argv, t_msh *msh);
int		ft_unset(char **argv, t_msh *msh);
char	*get_env_var(char *id, size_t len, char **envp);
void	ignore_sig(int sig);
bool	init_envp(char **src, char ***envp);
char	*join_path(char *path1, char *path2);
void	safe_close(int *fd);
bool	set_env_var(char *var, size_t id_len, t_msh *msh);
bool	set_env_var_id(char *id, char *value, t_msh *msh);
void	shift_strs(char **strs, bool free_str);
void	unset_declare(char *id, t_list **declare);

#endif
