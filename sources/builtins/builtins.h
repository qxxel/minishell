/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:59:42 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/27 11:43:35 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "msh_commons.h"

# define EXPORT_INVALID_ID	"minishell: export: `%s': not a valid identifier\n"
# define EXPORT_PREFIX		"declare -x %s"

#endif
