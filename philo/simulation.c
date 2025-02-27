/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:34:02 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/27 10:00:07 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*simulation_1(void *arg)
{
	t_philos	*philo;
	t_time		start;

	philo = (t_philos *)arg;
	if (philo->data->nbr_p == 1)
		one_philo(philo);
	gettimeofday(&start, NULL);
	gettimeofday(&(philo->last_meal_time), NULL);
	while (philo->data->alive)
	{
		taken_fork(philo, start);
		eating(philo, start);
		sleeping_thinking(philo, start);
	}
	return (NULL);
}

void	*simulation_2(void *arg)
{
	t_philos	*philo;
	t_time		start;

	philo = (t_philos *)arg;
	if (philo->data->option_arg == 0)
		return (NULL);
	if (philo->data->nbr_p == 1)
		one_philo(philo);
	gettimeofday(&start, NULL);
	gettimeofday(&(philo->last_meal_time), NULL);
	while (philo->data->alive)
	{
		taken_fork(philo, start);
		eating(philo, start);
		philo->number_eat++;
		if (philo->number_eat == philo->data->option_arg)
			break ;
		sleeping_thinking(philo, start);
	}
	return (NULL);
}
