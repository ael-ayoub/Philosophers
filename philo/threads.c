/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:34:05 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/03 02:23:40 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	create_threads(t_data *data, t_thread *thread)
{
	int	i;
	int	number;

	i = 0;
	number = data->number;
	gettimeofday(&data->start, NULL);
	while (i < number)
	{
		if (pthread_create(&thread[i].id, NULL, (void *)(*simulation),
			&thread[i]))
		{
			printf("error in initialization of thread\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	join_threads(t_data *data, t_thread *thread, t_monitor *monitor)
{
	int	i;

	i = 0;
	pthread_join(monitor->id_monitor, NULL);
	while (i < data->number)
	{
		pthread_join(thread[i].id, NULL);
		i++;
	}
}

t_thread	*init_threads(t_data *data)
{
	int			i;
	t_thread	*threads;

	threads = (t_thread *)malloc(sizeof(t_thread) * data->number);
	if (!threads)
		return (NULL);
	i = 0;
	while (i < data->number)
	{
		threads[i].data = data;
		threads[i].number_eat = 0;
		threads[i].index = i + 1;
		threads[i].left = &data->forks[i];
		threads[i].right = &data->forks[(i + 1) % data->number];
		i++;
	}
	return (threads);
}
