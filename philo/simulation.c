/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:34:02 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 14:53:29 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*simulation_1(void *arg)
{
	t_philos	*philo;
	t_time		start;
	t_time		end;

	philo = (t_philos *)arg;
	gettimeofday(&start, NULL);
	gettimeofday(&(philo->last_meal_time), NULL);
	if (philo->id_philo % 2 == 0)
		usleep(1000);
	while (philo->data->alive)
	{
		taken_fork(philo, start);
		gettimeofday(&end, NULL);
		eating(philo, start, end);
		gettimeofday(&(philo->last_meal_time), NULL);
		gettimeofday(&end, NULL);
		sleeping(philo, start, end);
		gettimeofday(&end, NULL);
		thinking(philo, start, end);
	}
	return (NULL);
}

void	*simulation_2(void *arg)
{
	t_philos	*philo;
	t_time		start;
	t_time		end;

	philo = (t_philos *)arg;
	gettimeofday(&start, NULL);
	gettimeofday(&(philo->last_meal_time), NULL);
	if (philo->data->option_arg == 0)
		return (NULL);
	if (philo->id_philo % 2 == 0)
		usleep(1000);
	while (philo->data->alive)
	{
		taken_fork(philo, start);
		gettimeofday(&end, NULL);
		eating(philo, start, end);
		philo->number_eat++;
		if (philo->number_eat == philo->data->option_arg)
			break ;
		gettimeofday(&(philo->last_meal_time), NULL);
		gettimeofday(&end, NULL);
		sleeping(philo, start, end);
	}
	return (NULL);
}
