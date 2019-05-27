/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:09:59 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/05/27 18:33:11 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// static int	len_itoa(int n)
// {
// 	int		len;

// 	len = 0;
// 	if (n == 0)
// 		return (1);
// 	if (n < 0)
// 	{
// 		if (n == -2147483648)
// 			return (11);
// 		n = -n;
// 		len++;
// 	}
// 	while (n > 9)
// 	{
// 		n = n / 10;
// 		len++;
// 	}
// 	len++;
// 	return (len);
// }

// char		*ft_itoa(int n)
// {
// 	int		len;
// 	char	*s;

// 	len = len_itoa(n);
// 	if ((s = malloc(len + 1)) == NULL)
// 		return (NULL);
// 	s[len--] = '\0';
// 	if (n < 0)
// 	{
// 		if (n == -2147483648)
// 		{
// 			s[len--] = 8 + 48;
// 			n = -214748364;
// 		}
// 		s[0] = '-';
// 		n = -n;
// 	}
// 	while (n > 9)
// 	{
// 		s[len--] = n % 10 + 48;
// 		n = n / 10;
// 	}
// 	s[len] = n + 48;
// 	return (s);
// }

static int len_num (int a)
{
	int len;

	len = 0;
	if (a < 0)
	{
		a = a * (-1);
		len++;
	}
	if (a == 2147483647)
		return (10);
	while (a != 0)
	{
		a = a / 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int a)
{
	char	*string;
	int len;

	if (a == -2147483648)
 		return ("-2147483648");
	if (a == 0)
		return ("0");
	len = len_num(a);
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len--] = '\0';
	if (a <= 0)
	{
		string[0] = '-';
		a = a * (-1);
	}
	while (a > 0)
	{
		string[len] = a % 10 + '0';
		a = a /10;
		len--;
	}
	return (string);
}

int main(void)
{
	int	a;

	printf("a = %ld | len = %s\n", -2147483648, ft_itoa(-2147483648));
	printf("a = %d | len = %s\n", 2147483647, ft_itoa(2147483647));
	printf("a = %d | len = %s\n", -1, ft_itoa(-1));
	printf("a = %d | len = %s\n", 0, ft_itoa(0));
	printf("a = %d | len = %s\n", 80, ft_itoa(80));
	printf("a = %d | len = %s\n", -400, ft_itoa(-400));
	printf("a = %d | len = %s\n", -5, ft_itoa(-5));
/*
	a = 0 == (-0)? 1 : 0;
	a = 5;
	printf("a = %d | len = %d\n", a, len_num(a));
	a = -1;
	printf("a = %d | len = %d\n", a, len_num(a));
	a = 400;
	printf("a = %d | len = %d\n", a, len_num(a));
	a = -400;
	printf("a = %d | len = %d\n", a, len_num(a));
	a = 10;
	printf("a = %d | len = %d\n", a, len_num(a));
	a = -15;
	printf("a = %d | len = %d\n", a, len_num(a));
*/
	// printf("\n");
	return (0);
}
