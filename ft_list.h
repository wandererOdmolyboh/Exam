/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:50:04 by wanderer          #+#    #+#             */
/*   Updated: 2019/05/27 16:13:02 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

typedef	struct		s_list
{
	int				data;
	struct s_list	*next;
}					t_list;



typedef struct 	s_point {
    int 		x;				// x : Width  | x-axis
    int 		y;				// y : Height | y-axis
} 				t_point;

