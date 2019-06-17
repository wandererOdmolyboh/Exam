/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:35:18 by wanderer          #+#    #+#             */
/*   Updated: 2019/06/17 23:12:00 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://github.com/lsauva/exam/blob/master/4-0-moment/moment.c

#include <stdlib.h>

char *ft_strcat(int dur, char *s)
{
	int len;
	int tmp;
	int start;
	char *stroke;

	len = 0;
	tmp = dur;
	while (s[len])
		len++;
	start = len;
	while ((tmp = tmp/ 10) > 0)
		len++;
	start = len - start;
	stroke = (char *)malloc(sizeof(char) * (len + 1));
	len = start;
	while (start != -1)
	{
		stroke[start--] = dur % 10 + '0';
		dur = dur / 10;
	}
	dur = 0;
	while (s[dur])
	 	stroke[++len] = s[dur++];
	stroke[++len] = '\0';
	return (stroke);
}

char    *moment(unsigned int duration)
{
	if (duration == 0)
		return ("0 seconds ago.");
	else if (duration == 1)
		return ("1 second ago.");
	else if (duration < 60)
		return (ft_strcat(duration, " seconds ago."));
	else if (duration == 60)
		return ("1 minute ago.");
	else if (duration < 60 * 60)
		return (ft_strcat(duration / 60, " minutes ago."));
	else if (duration < 60 * 60 * 2)
		return ("1 hour ago.");
	else if (duration < 60 * 60 * 12 * 2)
		return (ft_strcat(duration / (60 * 60), " hours ago."));
	else if (duration < 60 * 60 * 24 * 2)
		return ("1 day ago.");
	else if (duration < 60 * 60 * 24 * 30)
		return (ft_strcat(duration / (60 * 60 * 24 * 2), " days ago.")); //86400  2592000
	else if (duration < 60 * 60 * 24 * 2)
		return ("1 month ago.");
	else
		return (ft_strcat(duration / (60 * 60 * 24 * 30 * 2), " months ago."));
}
