/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:45:56 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/03 02:44:06 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	taken_fork(t_process *philo)
{
	t_time	end;
	t_time	start;

	start = philo->data->start;
	sem_wait(philo->data->mutex_fork);
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	sem_post(philo->data->mutex_fork);
	sem_wait(philo->data->lock);
	gettimeofday(&end, NULL);
	printf("%ld %d has taken a fork\n", set_time(start, end), philo->index);
	printf("%ld %d has taken a fork\n", set_time(start, end), philo->index);
	sem_post(philo->data->lock);
}

void	eating(t_process *philo)
{
	t_time	end;
	t_time	start;

	start = philo->data->start;
	sem_wait(philo->data->lock);
	gettimeofday(&end, NULL);
	printf("%ld %d is eating\n", set_time(start, end), philo->index);
	gettimeofday(&philo->last_meal_time, NULL);
	sem_post(philo->data->lock);
	usleep(1000 * philo->data->eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	sleeping(t_process *philo)
{
	t_time	end;
	t_time	start;

	start = philo->data->start;
	sem_wait(philo->data->lock);
	gettimeofday(&end, NULL);
	printf("%ld %d is sleeping\n", set_time(start, end), philo->index);
	sem_post(philo->data->lock);
	usleep(1000 * philo->data->sleep);
}

void	thinking(t_process *philo)
{
	t_time	end;
	t_time	start;

	start = philo->data->start;
	sem_wait(philo->data->lock);
	gettimeofday(&end, NULL);
	printf("%ld %d is thinking\n", set_time(start, end), philo->index);
	sem_post(philo->data->lock);
}
