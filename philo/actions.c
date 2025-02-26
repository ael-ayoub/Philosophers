/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:45:56 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 14:55:48 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	died(t_philos *philo, t_time start, t_time end)
{
	pthread_mutex_lock(&philo->data->write);
	if (set_time(philo->last_meal_time, end) > philo->data->die
		&& philo->data->alive != 0)
	{
		philo->data->alive = 0;
		printf("%ld %d died\n", set_time(start, end), philo->id_philo);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(&philo->data->write);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->write);
	return (1);
}

void	taken_fork(t_philos *philo, t_time start)
{
	t_time	end;

	if (philo->data->nbr_p == 1)
	{
		gettimeofday(&end, NULL);
		printf("%ld %d has taken a fork\n", set_time(start, end),
			philo->id_philo);
		philo->data->alive = 0;
		printf("%ld %d died\n", set_time(start, end), philo->id_philo);
		return ;
	}
	even_odd(start, philo);
	gettimeofday(&end, NULL);
	if (philo->data->alive == 0)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		return ;
	}
}

void	eating(t_philos *philo, t_time start, t_time end)
{
	pthread_mutex_lock(&philo->data->write);
	if (philo->data->alive == 0)
	{
		pthread_mutex_unlock(&philo->data->write);
		return ;
	}
	printf("%ld %d is eating\n", set_time(start, end), philo->id_philo);
	pthread_mutex_unlock(&philo->data->write);
	usleep(1000 * philo->data->eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	thinking(t_philos *philo, t_time start, t_time end)
{
	pthread_mutex_lock(&philo->data->write);
	if (philo->data->alive == 0)
	{
		pthread_mutex_unlock(&philo->data->write);
		return ;
	}
	printf("%ld %d is thinking\n", set_time(start, end), philo->id_philo);
	pthread_mutex_unlock(&philo->data->write);
}

void	sleeping(t_philos *philo, t_time start, t_time end)
{
	pthread_mutex_lock(&philo->data->write);
	if (philo->data->alive == 0)
	{
		pthread_mutex_unlock(&philo->data->write);
		return ;
	}
	printf("%ld %d is sleeping\n", set_time(start, end), philo->id_philo);
	pthread_mutex_unlock(&philo->data->write);
	usleep(1000 * philo->data->sleep);
	gettimeofday(&end, NULL);
	thinking(philo, start, end);
}
