/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_declare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:50:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/07/09 17:50:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_declare(char *id, t_list **declare)
{
	t_list	*element;

	if (!*declare)
		return ;
	if (!ft_strcmp(id, (*declare)->content))
	{
		ft_lstshift(declare, free);
		return ;
	}
	element = *declare;
	while (element)
	{
		if (!ft_strcmp(id, element->content))
		{
			ft_lstshift(&element, free);
			return ;
		}
		element = element->next;
	}
}
