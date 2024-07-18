/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:59:42 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/18 18:00:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "msh_commons.h"

# define CD_ARGS_ERROR		"minishell: cd: too many arguments\n"
# define CD_ERROR			"minishell: cd: %s: %s\n"
# define CD_PARENT_ERROR	"cd: error retrieving current directory: getcwd: \
cannot access parent directories: %s\n"
# define CD_VAR_ERROR		"minishell: cd: %s not set\n"
# define EXIT_ARG_ERROR		"minishell: exit: %s: numeric argument required\n"
# define EXIT_ARGS_ERROR	"minishell: exit: too many arguments\n"
# define EXPORT_ID_ERROR	"minishell: export: `%s': not a valid identifier\n"
# define EXPORT_PREFIX		"declare -x %s"
# define WRITE_ERROR		"minishell: %s: write error: %s\n"

bool	write_error(char *program);

#endif
