/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:16:28 by utoomey           #+#    #+#             */
/*   Updated: 2021/01/29 15:13:32 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

struct s_philosopher;
struct timeval				time_start;
struct timeval				time_point;

typedef struct				s_data
{
	int						count;
	int						end;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						count_cycle;
	sem_t					*sem_out;
	sem_t					*sem_forks;
	sem_t					*sem_death;
	sem_t					*sem_philosophers;
	pthread_t				*threads;
	struct s_philosopher	*philosophers;
}							t_data;

typedef struct				s_philosopher
{
	int						id;
	int						eat;
	int						counter;
	long					time_start;
	t_data					*data;
}							t_philosopher;

void						ft_putchar_fd(char *str, int fd);
int							ft_isdigit(int ch);
int							ft_atoi(const char *str);
char						*ft_itoa(int n);
void						*ft_calloc(size_t num, size_t size);
int							ft_error();
void						takes_forks(t_philosopher *philosopher);
void						put_forks(t_philosopher *philosopher);
void						*control_philosopher(void *data);
void						*cycle_philosopher(void *data);
int							get_permission_for_forks(t_philosopher *p);
void						philosopher_die(t_philosopher *philosopher);
void						philosopher_eat(t_philosopher *philosopher);
void						philosopher_sleep(t_philosopher *philosopher);
void						philosopher_think(t_philosopher *philosopher);
int							parse(t_data *data, char **argv);
void						free_all(t_data data);
void						ft_pthread_detach_all(t_data *data);
void						ft_control_die(t_philosopher *ids, int c);
void						ft_pthread_create_all(t_data *data);
void						print_message(int time, t_philosopher *p, char *m);
long						get_time(void);
int							get_lifetime(t_philosopher *philosopher);
void						ft_sleep(int t);
void						ft_pthread_wait(t_data *data);

#endif
