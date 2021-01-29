/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:09:01 by utoomey           #+#    #+#             */
/*   Updated: 2021/01/30 01:44:05 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	takes_forks(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->data->mutexs + philosopher->right);
	print_message(get_lifetime(philosopher), philosopher, \
	"has taken a fork");
	pthread_mutex_lock(philosopher->data->mutexs + philosopher->left);
	print_message(get_lifetime(philosopher), philosopher, \
	"has taken a fork");
}

void	put_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(philosopher->data->mutexs + philosopher->left);
	pthread_mutex_unlock(philosopher->data->mutexs + philosopher->right);
}
