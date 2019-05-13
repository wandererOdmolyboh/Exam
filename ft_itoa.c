/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:09:59 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/05/13 18:32:38 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	len_itoa(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*s;

	len = len_itoa(n);
	if ((s = ft_memalloc(len + 1)) == NULL)
		return (NULL);
	s[len--] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			s[len--] = 8 + 48;
			n = -214748364;
		}
		s[0] = '-';
		n = -n;
	}
	while (n > 9)
	{
		s[len--] = n % 10 + 48;
		n = n / 10;
	}
	s[len] = n + 48;
	return (s);
}
