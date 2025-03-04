/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:04:18 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/02 23:16:53 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	simulation(t_process *philo)
{
	if (philo->data->option_arg == 0)
	{
		sem_wait(philo->data->count);
		return ;
	}
	if (philo->data->number == 1)
		one_philo(philo, philo->data->start);
	gettimeofday(&philo->last_meal_time, NULL);
	pthread_create(&philo->monitor, NULL, (void *)(*monitor), (void *)philo);
	if (philo->data->option_arg == -1)
		simulation_1(philo);
	else
		simulation_2(philo);
	pthread_join(philo->monitor, NULL);
}

void	simulation_1(t_process *philo)
{
	while (1)
	{
		taken_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

void	simulation_2(t_process *philo)
{
	while (1)
	{
		taken_fork(philo);
		eating(philo);
		sem_wait(philo->data->lock);
		philo->number_eat++;
		if (philo->number_eat == philo->data->option_arg)
		{
			sem_wait(philo->data->count);
			sem_post(philo->data->lock);
			break ;
		}
		sem_post(philo->data->lock);
		sleeping(philo);
		thinking(philo);
	}
}
