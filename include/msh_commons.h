/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_commons.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:17:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/24 08:48:02 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_COMMONS_H
# define MSH_COMMONS_H

# include <dirent.h>
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

int		ft_echo(char **argv, char ***envp);
int		ft_env(char **argv, char ***envp);
char	*get_env_var(char *name, size_t len, char **envp);
bool	set_env_var(char *var, size_t name_len, char ***envp);

#endif
