/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 02:20:56 by utoomey           #+#    #+#             */
/*   Updated: 2021/01/28 02:21:13 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	takes_forks(t_philosopher *philosopher)
{
	sem_wait(philosopher->data->sem_forks);
	print_message(get_lifetime(philosopher), philosopher, "has taken a fork");
	sem_wait(philosopher->data->sem_forks);
	print_message(get_lifetime(philosopher), philosopher, "has taken a fork");
}

void	put_forks(t_philosopher *philosopher)
{
	sem_post(philosopher->data->sem_forks);
	sem_post(philosopher->data->sem_forks);
}

void	takes_forks_2(t_philosopher *philosopher)
{
	sem_wait(philosopher->data->sem_forks);
	print_message(get_lifetime(philosopher), philosopher, "has taken a fork");
	sem_wait(philosopher->data->sem_forks);
	print_message(get_lifetime(philosopher), philosopher, "has taken a fork");
}

void	put_forks_2(t_philosopher *philosopher)
{
	sem_post(philosopher->data->sem_forks);
	sem_post(philosopher->data->sem_forks);
}
