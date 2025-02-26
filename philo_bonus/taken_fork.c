/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:53:14 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 11:56:21 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	print_actions(t_philos *philo, t_time start)
{
	t_time	end;

	sem_wait(philo->data->write);
	gettimeofday(&end, NULL);
	printf("%ld %d has taken a fork\n", set_time(start, end), philo->id_philo);
	printf("%ld %d has taken a fork\n", set_time(start, end), philo->id_philo);
	sem_post(philo->data->write);
}

void	taken_fork_1(t_philos *philo, t_time start)
{
	t_time	end;

	sem_wait(philo->data->mutex_fork);
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	sem_post(philo->data->mutex_fork);
	gettimeofday(&end, NULL);
	if (set_time(philo->last_meal_time, end) > philo->data->die)
	{
		sem_wait(philo->data->write);
		gettimeofday(&end, NULL);
		printf("%ld %d died\n", set_time(start, end), philo->id_philo);
		sem_post(philo->data->alive);
	}
	print_actions(philo, start);
}

void	taken_fork_2(t_philos *philo, t_time start)
{
	t_time	end;

	sem_wait(philo->data->mutex_fork);
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	sem_post(philo->data->mutex_fork);
	gettimeofday(&end, NULL);
	if (set_time(philo->last_meal_time, end) > philo->data->die)
	{
		sem_wait(philo->data->write);
		gettimeofday(&end, NULL);
		printf("%ld %d died\n", set_time(start, end), philo->id_philo);
		while (philo->data->nbr_p)
		{
			sem_post(philo->data->count);
			philo->data->nbr_p--;
		}
	}
	print_actions(philo, start);
}
