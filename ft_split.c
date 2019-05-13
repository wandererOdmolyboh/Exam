/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:13:25 by wanderer          #+#    #+#             */
/*   Updated: 2019/05/06 15:28:03 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    **ft_split(char *str)
{
	int i;
	int j;
	int k;
	char **tab;

	i = 0;
	j = 0;
	tab = (char**)malloc(sizeof(**tab) * 1000);
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			k = 0;
			tab[j] = (char*)malloc(sizeof(char) * 1000);
			while (str[i] > 32)
				tab[j][k++] = str[i++];
			tab[j++][k] = '\0';
		}
		else
			i++;
	}
	tab[j] = '\0';
	return (tab);
}

int main()
{
	char *s;
	char **t;
	int i;
	
	i = 0;
	s = "qwe hello world";
	t = ft_split(s);
	while (t[i])
	{
		printf("%s\n", t[i]);
		i++;
	}
	return 0;
}