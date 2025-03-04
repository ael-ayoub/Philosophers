/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:34:02 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/03 03:56:55 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	simulation(t_thread *philo)
{
	if (philo->data->option_arg == 0)
		return ;
	if (philo->data->number == 1)
	{
		one_philo(philo);
		return ;
	}
	if (philo->data->option_arg == -1)
		simulation_1(philo);
	else
		simulation_2(philo);
}

void	*simulation_1(t_thread *philo)
{
	gettimeofday(&(philo->last_meal_time), NULL);
	while (1)
	{
		pthread_mutex_lock(philo->data->write);
		if (!philo->data->alive)
		{
			pthread_mutex_unlock(philo->data->write);
			return (NULL);
		}
		pthread_mutex_unlock(philo->data->write);
		taken_fork(philo);
		eating(philo);
		sleeping_thinking(philo);
	}
	return (NULL);
}

void	*simulation_2(t_thread *philo)
{
	gettimeofday(&(philo->last_meal_time), NULL);
	while (1)
	{
		pthread_mutex_lock(philo->data->write);
		if (!philo->data->alive)
		{
			pthread_mutex_unlock(philo->data->write);
			break ;
		}
		pthread_mutex_unlock(philo->data->write);
		taken_fork(philo);
		eating(philo);
		pthread_mutex_lock(philo->data->write);
		philo->number_eat++;
		if (philo->number_eat == philo->data->option_arg)
		{
			philo->data->count--;
			pthread_mutex_unlock(philo->data->write);
			break ;
		}
		pthread_mutex_unlock(philo->data->write);
		sleeping_thinking(philo);
	}
	return (NULL);
}
