/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 02:33:26 by utoomey           #+#    #+#             */
/*   Updated: 2021/01/29 15:13:55 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	t_data			data;

	if ((argc != 5 && argc != 6) || parse(&data, argv + 1))
		return (ft_error());
	create_processes(&data);
	wait_processes(&data);
	free_all(data);
	return (0);
}
