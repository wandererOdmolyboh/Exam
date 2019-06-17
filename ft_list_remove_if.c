/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:18:32 by wanderer          #+#    #+#             */
/*   Updated: 2019/06/17 23:10:54 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*new_begin_list;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	new_begin_list = *begin_list;
	while (new_begin_list && new_begin_list->next)
	{
		if (cmp(new_begin_list->next->data, data_ref) == 0)
		{
			tmp = new_begin_list->next;
			new_begin_list->next = tmp->next;
			free(tmp);
		}
		if (new_begin_list->next)
			new_begin_list = new_begin_list->next;
	}
}