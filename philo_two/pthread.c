/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:41:19 by utoomey           #+#    #+#             */
/*   Updated: 2021/01/29 15:13:26 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_pthread_detach_all(t_data *data)
{
	int i;

	i = 0;
	while (i < data->count)
		pthread_detach(data->threads[i++]);
}

void	ft_pthread_join_all(t_data *data)
{
	int i;

	i = 0;
	while (i < data->count)
		pthread_join(data->threads[i++], NULL);
}

void	ft_pthread_wait(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		sem_wait(data->sem_philosophers);
		sem_wait(data->sem_philosophers);
		i++;
	}
}

void	ft_pthread_create_all(t_data *data)
{
	int i;

	i = 1;
	while (i < data->count)
	{
		pthread_create(&data->threads[i], NULL, \
		cycle_philosopher, &(data->philosophers[i]));
		i += 2;
	}
	usleep(120);
	i = 0;
	while (i < data->count)
	{
		pthread_create(&data->threads[i], NULL, \
		cycle_philosopher, &(data->philosophers[i]));
		i += 2;
	}
}
