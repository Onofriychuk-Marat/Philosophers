/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:08:54 by utoomey           #+#    #+#             */
/*   Updated: 2021/01/29 17:47:15 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*control_philosopher(void *data)
{
	while (!((t_philosopher*)data)->end)
	{
		((t_philosopher*)data)->eat = 0;
		ft_sleep(((t_philosopher*)data)->data->time_to_die);
		if (((t_philosopher*)data)->end)
			return (NULL);
		if (!((t_philosopher*)data)->eat)
		{
			pthread_mutex_lock(&(((t_philosopher*)data)->data->death2));
			philosopher_die(((t_philosopher*)data));
			((t_philosopher*)data)->data->end = 1;
			pthread_mutex_unlock(&(((t_philosopher*)data)->data->death));
			return (NULL);
		}
	}
	return (NULL);
}
