/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:04:18 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 20:21:17 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	simulation_1(t_philos *philo)
{
	t_time	start;

	gettimeofday(&start, NULL);
	if (philo->data->nbr_p == 1)
		one_philo_1(philo, start);
	gettimeofday(&(philo->last_meal_time), NULL);
	while (1)
	{
		taken_fork_1(philo, start);
		eating(philo, start);
		sleeping(philo, start);
		thinking(philo, start);
	}
}

void	simulation_2(t_philos *philo)
{
	t_time	start;

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
		eating(philo, start);
		philo->number_eat++;
		if (philo->number_eat == philo->data->option_arg)
			break ;
		sleeping(philo, start);
		thinking(philo, start);
	}
	sem_post(philo->data->count);
}
