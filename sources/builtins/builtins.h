/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:59:42 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/28 13:03:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "msh_commons.h"

# define CD_ARGS_ERROR		"minishell: cd: too many arguments\n"
# define CD_ERROR			"minishell: cd: %s: %s\n"
# define CD_VAR_ERROR		"minishell: cd: %s not set\n"
# define EXPORT_ID_ERROR	"minishell: export: `%s': not a valid identifier\n"
# define EXPORT_PREFIX		"declare -x %s"

#endif
