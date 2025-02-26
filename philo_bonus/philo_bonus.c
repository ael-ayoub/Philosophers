/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:05:31 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 11:29:32 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	create_philosophers(t_philos *philos, void (simulation) (t_philos *),
	int nbr_p)
{
	int	i;

	i = 0;
	while (i < nbr_p)
	{
		philos[i].id_process = fork();
		if (philos[i].id_process == 0)
		{
			simulation(&philos[i]);
			cleanup_child(philos, philos->data);
			exit(0);
		}
		i++;
	}
}

void	wait_for_processes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_p)
	{
		sem_wait(data->count);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_philos	*philos;
	t_data		data;

	if (!initialize_simulation(ac, av, &philos, &data))
		return (0);
	if (philos->data->option_arg == -1)
	{
		create_philosophers(philos, simulation_1, philos->data->nbr_p);
		sem_wait(data.alive);
	}
	else
	{
		create_philosophers(philos, simulation_2, philos->data->nbr_p);
		wait_for_processes(&data);
	}
	kill_processes(philos);
	cleanup(philos, &data);
	return (0);
}
