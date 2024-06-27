/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_commons.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:17:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/27 18:07:54 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_COMMONS_H
# define MSH_COMMONS_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# include "libft.h"
# include "msh_types.h"

int		ft_cd(char **argv, t_msh *msh);
int		ft_echo(char **argv, t_msh *msh);
int		ft_env(char **argv, t_msh *msh);
int		ft_export(char **argv, t_msh *msh);
int		ft_pwd(char **argv, t_msh *msh);
char	*get_env_var(char *id, size_t len, char **envp);
bool	set_env_var(char *var, size_t id_len, char ***envp);
bool	set_env_var_id(char *id, char *value, char ***envp);

#endif
