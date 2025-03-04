/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:33:45 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/03 02:23:40 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	validate_args(int ac, char *av[], t_data *data)
{
	if (ac != 5 && ac != 6)
	{
		printf("invalid syntax.\n");
		return (0);
	}
	if (ac == 5)
	{
		if (!init_data_1(data, av))
		{
			printf("invalid arguments.\n");
			return (0);
		}
	}
	else if (!init_data_2(data, av))
	{
		printf("invalid arguments.\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_thread	*thread;
	t_monitor	*monitor;
	t_data		data;

	if (!validate_args(ac, av, &data))
		return (0);
	thread = init_threads(&data);
	if (!thread)
	{
		printf("Error in initialisation of threads\n");
		return (0);
	}
	monitor = init_monitor(thread);
	pthread_create(&monitor->id_monitor, NULL, (void *)monitor_function,
		(void *)monitor);
	if (!create_threads(&data, thread))
	{
		cleanup(&data, thread, monitor);
		return (0);
	}
	join_threads(&data, thread, monitor);
	cleanup(&data, thread, monitor);
	return (0);
}
