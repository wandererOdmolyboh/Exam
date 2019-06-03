/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:23:50 by wanderer          #+#    #+#             */
/*   Updated: 2019/06/02 18:30:43 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_isblanka(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_putstr(char *start)
{
	int	i;

	i = 0;
	while (start[i] && ft_isblanka(start[i]))
		i++;
	while (start[i])
	{
		if (ft_isblanka(start[i]))
		{
			while (start[i] && ft_isblanka(start[i]))
				i++;
			if (start[i])
				write(1, " ", 1);
			else
				break ;
		}
		write(1, &start[i], 1);
		i++;
	}
}

void	rostring(char *start)
{
	int	i;
	int	end;
	int	test;

	i = 0;
	while (start[i] && ft_isblanka(start[i]))
		i++;
	test = i;
	while (start[i] && !ft_isblanka(start[i]))
		i++;
	end = i;
	while (start[i] && ft_isblanka(start[i]))
		i++;
	ft_putstr(&start[i]);
	start[i] ? write(1, " ", 1) : write(0, "", 0);
	i = test;
	while (i != end)
			write(1, &start[i++], 1);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int	i;

	i = 2;
	if (argc >= 2)
	{
		rostring(argv[1]);
		while (argv[i])
		{
			ft_putstr(argv[i++]);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
//./a.out "11 ewqq   eqwewq      "  dsa 111 " 11  222"| cat -e