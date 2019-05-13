/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:28:37 by wanderer          #+#    #+#             */
/*   Updated: 2019/05/06 15:08:19 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_brainefuck(char *str)
{
	char *ptr;
	int loop;
	int i;

	i = 0;
	if ((ptr = (char *)malloc(sizeof(char) * 2048)) == NULL)
		return ;
	while (str[i])
	{
		*ptr += str[i] == '+' ? 1 : 0;
		*ptr -= str[i] == '-' ? 1 : 0;
		ptr += str[i] == '>' ? 1 : 0;
		ptr -= str[i] == '<' ? 1 : 0;
		if (str[i] && str[i] == '.')
			write (1, ptr, 1);
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
}

void fprime (int nbr)
{
	unsigned int	prime;

	if (nbr == 1)
		printf("1");
	else
	{
		prime = 2;
		while(nbr > 1)
		{
			if (nbr % prime == 0)
			{
				printf("%d", prime);
				nbr /= prime;
				if (nbr > 1)
					printf("*");
				prime--;
			}
			prime++;
		}
	}
	printf("\n");
}

int main(int argc, char **argv)
{
//	int a = (2) ^ 30;
	 fprime(10);
	return (0);
}