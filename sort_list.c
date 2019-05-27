/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:56:24 by wanderer          #+#    #+#             */
/*   Updated: 2019/05/27 16:15:15 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

int			ascending(int a, int b)
{
	return (a <= b);
}

void		swap(t_list *one, t_list *two)
{
	int		tmp;

	tmp = one->data;
	one->data = two->data;
	two->data = tmp;
}

t_list		*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*current;
	t_list	*tmp;

	if (!lst)
		return (lst);
	if (!lst->next)
		return (lst->next);
	current = lst;
	tmp = lst;
	while (tmp->next)
	{
		current = lst;
		while (current->next)
		{
			if ((*cmp)(current->data, current->next->data))
				current = current->next;
			else
				swap(current, current->next);
		}
		tmp = tmp->next;
	}
	return (lst);
}

int main(void)
{
    t_list *tmp;
    t_list	*tmp1;
    t_list	*tmp2;
    t_list	*tmp3;
    t_list	*tmp4;
    t_list	*tmp5;

    
    tmp1 = (t_list *) malloc(sizeof(t_list));
    tmp2 = (t_list *) malloc(sizeof(t_list));
    tmp3 = (t_list *) malloc(sizeof(t_list));
    tmp4 = (t_list *) malloc(sizeof(t_list));
    tmp5 = (t_list *) malloc(sizeof(t_list));

    tmp1->next = tmp2;
    tmp2->next = tmp3;
    tmp3->next = tmp4;
    tmp4->next = tmp5;
    tmp5->next = NULL;
    tmp = tmp2;
    tmp1->data = -1.5;
    tmp2->data = 438;
    tmp3->data = 4324;
    tmp4->data = 5893;
    tmp5->data = 65021;
    
   // ,,,
    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    tmp = sort_list(tmp2, ascending);
    printf("\n");
        while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    return (0);
}