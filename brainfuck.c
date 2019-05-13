/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:02:59 by exam              #+#    #+#             */
/*   Updated: 2019/05/06 14:26:59 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int   ft_brainfuck(char *str)
{
	int  i;
	char *ptr;
	int  loop;
	
	if ((ptr = (char *)malloc(sizeof(char) * 2048)) == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		*ptr += str[i] == '+' ? 1 : 0;
		*ptr -= str[i] == '-' ? 1 : 0;
		ptr += str[i] == '>' ? 1 : 0;
		ptr -= str[i] == '<' ? 1 : 0;
		if (str[i] == '.')
			write(1, ptr, 1);
		if (str[i] == '[')
		{
			loop = 1;
			while (loop)
			{
				i++;
				loop += str[i] == '[' ? 1 : 0;
				loop -= str[i] == ']' ? 1 : 0;
			}
		}
		if (str[i] == ']' && *ptr)
		{
			loop = 1;
			while (loop)
			{
				i--;
				loop += str[i] == ']' ? 1 : 0;
				loop -= str[i] == '[' ? 1 : 0;
			}
		}
		i++;
	}
	return (0);
}

int   main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0])
		ft_brainfuck(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
