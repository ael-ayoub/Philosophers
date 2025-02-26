/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:31:31 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/25 16:33:21 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	init_data_1(t_data *data, char **av)
{
	int	i;

	if (!init_time_1(av, data))
		return (0);
	pthread_mutex_init(&data->write, NULL);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nbr_p);
	if (!data->forks)
	{
		pthread_mutex_destroy(&data->write);
		return (0);
	}
	i = 0;
	while (i < data->nbr_p)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	data->alive = 1;
	return (1);
}

int	init_data_2(t_data *data, char **av)
{
	int	i;

	if (!init_time_2(av, data))
		return (0);
	pthread_mutex_init(&data->write, NULL);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nbr_p);
	if (!data->forks)
	{
		pthread_mutex_destroy(&data->write);
		return (0);
	}
	i = 0;
	while (i < data->nbr_p)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	data->alive = 1;
	return (1);
}
