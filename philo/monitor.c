/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:55:50 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/03 04:03:35 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_monitor	*init_monitor(t_thread *philo)
{
	t_monitor	*monitor;

	if (!philo)
		return (NULL);
	monitor = malloc(sizeof(t_monitor));
	monitor->thread = philo;
	return (monitor);
}

static int	check_death_1(t_monitor *monitor, int i)
{
	t_time	end;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(monitor->thread->data->write);
	if (set_time(monitor->thread[i].last_meal_time,
			end) > monitor->thread->data->die)
	{
		monitor->thread[i].data->alive = 0;
		printf("%ld %d died\n", set_time(monitor->thread[i].data->start, end),
			monitor->thread[i].index);
		pthread_mutex_unlock(monitor->thread[i].data->write);
		return (0);
	}
	pthread_mutex_unlock(monitor->thread[i].data->write);
	return (1);
}

static int	check_death_2(t_monitor *monitor, int i)
{
	t_time	end;

	pthread_mutex_lock(monitor->thread[i].data->write);
	if (monitor->thread[i].data->count == 0)
	{
		pthread_mutex_unlock(monitor->thread[i].data->write);
		return (0);
	}
	if (monitor->thread[i].number_eat == monitor->thread[i].data->option_arg)
	{
		pthread_mutex_unlock(monitor->thread[i].data->write);
		return (1);
	}
	gettimeofday(&end, NULL);
	if (set_time(monitor->thread[i].last_meal_time,
			end) > monitor->thread->data->die)
	{
		monitor->thread[i].data->alive = 0;
		printf("%ld %d died\n", set_time(monitor->thread[i].data->start, end),
			monitor->thread[i].index);
		pthread_mutex_unlock(monitor->thread[i].data->write);
		return (0);
	}
	pthread_mutex_unlock(monitor->thread[i].data->write);
	return (1);
}

void	monitor_function(t_monitor *monitor)
{
	int		i;
	t_data	*data;

	i = 0;
	data = monitor->thread->data;
	if (data->number == 1 || data->option_arg == 0)
		return ;
	usleep(1000);
	while (i < data->number)
	{
		if (data->option_arg == -1)
		{
			if (!check_death_1(monitor, i))
				return ;
		}
		else
		{
			if (!check_death_2(monitor, i))
				return ;
		}
		i++;
		if (i == data->number - 1)
			i = 0;
		usleep(1000);
	}
}
