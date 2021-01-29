/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 02:26:55 by utoomey           #+#    #+#             */
/*   Updated: 2021/01/29 15:14:15 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	wait_processes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		sem_wait(data->sem_philosophers);
		sem_wait(data->sem_philosophers);
		i++;
	}
	i = -1;
	while (++i < data->count)
		kill(data->processes[i], SIGKILL);
}

void	create_processes(t_data *data)
{
	int i;

	i = 1;
	while (i < data->count)
	{
		if (!(data->processes[i] = fork()))
		{
			cycle_philosopher(&(data->philosophers[i]));
		}
		i += 2;
	}
	usleep(50);
	i = 0;
	while (i < data->count)
	{
		if (!(data->processes[i] = fork()))
		{
			cycle_philosopher(&(data->philosophers[i]));
		}
		i += 2;
	}
}
