/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:09:13 by utoomey           #+#    #+#             */
/*   Updated: 2021/01/30 01:43:27 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	philosopher_die(t_philosopher *philosopher)
{
	print_message(get_lifetime(philosopher), \
	philosopher, "died");
}

void	philosopher_eat(t_philosopher *philosopher)
{
	takes_forks(philosopher);
	print_message(get_lifetime(philosopher), \
	philosopher, "is eating");
	ft_sleep(philosopher->data->time_to_eat);
	philosopher->eat = 1;
	put_forks(philosopher);
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	print_message(get_lifetime(philosopher), \
	philosopher, "is sleeping");
	ft_sleep(philosopher->data->time_to_sleep);
}

void	philosopher_think(t_philosopher *philosopher)
{
	print_message(get_lifetime(philosopher), \
	philosopher, "is thinking");
}

void	*cycle_philosopher(void *data)
{
	t_philosopher	*philosopher;
	pthread_t		thread;

	philosopher = (t_philosopher*)data;
	philosopher->time_start = get_time();
	pthread_create(&thread, NULL, control_philosopher, data);
	pthread_detach(thread);
	while (philosopher->data->count_cycle == -1 ||
	++philosopher->counter <= philosopher->data->count_cycle)
	{
		philosopher_eat((t_philosopher*)data);
		philosopher_sleep((t_philosopher*)data);
		philosopher_think((t_philosopher*)data);
	}
	pthread_mutex_unlock(&(((t_philosopher*)data)->data->death));
	((t_philosopher*)data)->end = 1;
	return (NULL);
}
