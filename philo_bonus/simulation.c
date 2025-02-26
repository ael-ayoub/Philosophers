/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:04:18 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 15:17:53 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	simulation_1(t_philos *philo)
{
	t_time	start;
	t_time	end;

	gettimeofday(&start, NULL);
	if (philo->data->nbr_p == 1)
		one_philo_1(philo, start);
	gettimeofday(&(philo->last_meal_time), NULL);
	while (1)
	{
		taken_fork_1(philo, start);
		gettimeofday(&end, NULL);
		eating(philo, start);
		gettimeofday(&(philo->last_meal_time), NULL);
		sleeping(philo, start);
		thinking(philo, start);
	}
}

void	simulation_2(t_philos *philo)
{
	t_time	start;
	t_time	end;

	gettimeofday(&start, NULL);
	if (philo->data->option_arg == 0)
	{
		sem_post(philo->data->count);
		return ;
	}
	if (philo->data->nbr_p == 1)
		one_philo_2(philo, start);
	gettimeofday(&(philo->last_meal_time), NULL);
	while (1)
	{
		taken_fork_2(philo, start);
		gettimeofday(&end, NULL);
		eating(philo, start);
		gettimeofday(&(philo->last_meal_time), NULL);
		philo->number_eat++;
		if (philo->number_eat == philo->data->option_arg)
			break ;
		sleeping(philo, start);
		thinking(philo, start);
	}
	sem_post(philo->data->count);
}
