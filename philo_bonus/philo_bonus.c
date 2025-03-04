/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:05:31 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/02 02:35:16 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	main(int ac, char *av[])
{
	t_process	*philos;
	t_data		data;

	if (!initialize_simulation(ac, av, &philos, &data))
		return (0);
	if (!create_processes(philos))
	{
		kill_processes(philos);
		cleanup(philos, &data);
		return (1);
	}
	if (philos->data->option_arg == -1)
	{
		while (1)
		{
			if (data.alive->__align == 0)
				break ;
		}
	}
	else
		wait_for_processes(&data);
	kill_processes(philos);
	cleanup(philos, &data);
	return (0);
}
