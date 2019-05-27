/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:32:14 by wanderer          #+#    #+#             */
/*   Updated: 2019/05/27 15:47:46 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"


void		floood_fill(char **tab, t_point size, t_point point, char colorr)
{
	t_point	tmp;

	if ((point.x > (size.x - 1) || point.x < 0) || (point.y < 0 || point.y > (size.y - 1)))
		return ;
	if (colorr != tab[point.y][point.x])
		return ;
	tab[point.y][point.x] = 'F';
	tmp.x = point.x + 1;
	tmp.y = point.y;
	floood_fill(tab, size, tmp, colorr);
	tmp.x = point.x - 1;
	tmp.y = point.y;
	floood_fill(tab, size, tmp, colorr);
	tmp.x = point.x;
	tmp.y = point.y + 1;
	floood_fill(tab, size, tmp, colorr);
	tmp.x = point.x;
	tmp.y = point.y - 1;
	floood_fill(tab, size, tmp, colorr);
}

void		flood_fill(char **tab, t_point size, t_point begin)
{
	floood_fill(tab, size, begin, tab[begin.y][begin.x]);
}



char **make_area(char **zone, int _x, int _y)
{
	char **area;
	area = (char **)malloc(sizeof(char *) * _y);
	for (int i = 0; i < _y; ++i)
	{
		area[i] = (char *)malloc(sizeof(char) * _x);
		for (int j = 0; j < _x; ++j)
		{
			area[i][j] = zone[i][2 * j];
		}
	}
	return (area);
}

int main(void)
{
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 0 1 0 0 0 0 1",
	};
	t_point size  = {8, 5};
	t_point begin = {2, 2};
	char **area = make_area(zone, size.x, size.y);
	flood_fill(area, size, begin);
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (x != 0)
				printf(" ");
			printf("%c", area[y][x]);
		}
		printf("\n");
	}
	free(area);
	return (0);
}
