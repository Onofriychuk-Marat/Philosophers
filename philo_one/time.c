/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:09:18 by utoomey           #+#    #+#             */
/*   Updated: 2021/01/29 17:56:19 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * (long)1000) + (tv.tv_usec / (long)1000)));
}

int		get_lifetime(t_philosopher *philosopher)
{
	long	time;

	time = get_time();
	return (time - philosopher->time_start);
}

void	ft_sleep(int t)
{
	long int	s;
	long int	e;

	s = get_time();
	while (1)
	{
		usleep(200);
		e = get_time();
		if (e - s >= (long int)t)
			return ;
	}
}
