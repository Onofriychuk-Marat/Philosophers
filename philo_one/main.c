/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:09:08 by utoomey           #+#    #+#             */
/*   Updated: 2021/01/29 17:31:04 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	t_data			data;

	if ((argc != 5 && argc != 6) || parse(&data, argv + 1))
		return (ft_error());
	ft_pthread_detach_all(&data);
	ft_pthread_create_all(&data);
	ft_pthread_wait(&data, (argc == 6));
	free_all(data);
	return (0);
}
