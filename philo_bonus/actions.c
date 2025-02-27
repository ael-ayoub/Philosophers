/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:45:56 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 20:20:49 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	eating(t_philos *philo, t_time start)
{
	t_time	end;

	sem_wait(philo->data->write);
	gettimeofday(&(philo->last_meal_time), NULL);
	gettimeofday(&end, NULL);
	printf("%ld %d is eating\n", set_time(start, end), philo->id_philo);
	sem_post(philo->data->write);
	usleep(1000 * philo->data->eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	sleeping(t_philos *philo, t_time start)
{
	t_time	end;

	gettimeofday(&end, NULL);
	sem_wait(philo->data->write);
	printf("%ld %d is sleeping\n", set_time(start, end), philo->id_philo);
	sem_post(philo->data->write);
	usleep(1000 * philo->data->sleep);
}

void	thinking(t_philos *philo, t_time start)
{
	t_time	end;

	sem_wait(philo->data->write);
	gettimeofday(&end, NULL);
	printf("%ld %d is thinking\n", set_time(start, end), philo->id_philo);
	sem_post(philo->data->write);
}
