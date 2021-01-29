/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 02:20:12 by utoomey           #+#    #+#             */
/*   Updated: 2021/01/29 14:21:54 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*control_philosopher(void *data)
{
	int i;

	while (1)
	{
		((t_philosopher*)data)->eat = 0;
		ft_sleep(((t_philosopher*)data)->data->time_to_die);
		if (!((t_philosopher*)data)->eat)
		{
			sem_wait(((t_philosopher*)data)->data->sem_death);
			philosopher_die(((t_philosopher*)data));
			i = 0;
			while (i++ < ((t_philosopher*)data)->data->count)
			{
				sem_post(((t_philosopher*)data)->data->sem_philosophers);
			}
			return (NULL);
		}
	}
	return (NULL);
}
