/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:34:05 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 14:46:45 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	create_thread_group(t_philos *philos, int nbr_p,
		void *(*simulation)(void *))
{
	int	i;

	i = 0;
	while (i < nbr_p)
	{
		if (pthread_create(&philos[i].id_thread, NULL, simulation,
				(void *)&philos[i]))
		{
			printf("error in initialization of thread\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	create_threads(t_data *data, t_philos *philos)
{
	if (data->option_arg == -1)
		return (create_thread_group(philos, data->nbr_p, simulation_1));
	else
		return (create_thread_group(philos, data->nbr_p, simulation_2));
}

void	join_threads(t_data *data, t_philos *philos)
{
	int	i;

	i = 0;
	while (i < data->nbr_p)
	{
		pthread_join(philos[i].id_thread, NULL);
		i++;
	}
}

t_philos	*init_threads(t_data *data)
{
	int			i;
	t_philos	*threads;

	threads = (t_philos *)malloc(sizeof(t_philos) * data->nbr_p);
	if (!threads)
		return (NULL);
	i = 0;
	while (i < data->nbr_p)
	{
		threads[i].data = data;
		threads[i].number_eat = 0;
		threads[i].id_philo = i + 1;
		threads[i].left = &data->forks[i];
		threads[i].right = &data->forks[(i + 1) % data->nbr_p];
		i++;
	}
	return (threads);
}
