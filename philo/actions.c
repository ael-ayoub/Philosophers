/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:45:56 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/27 10:06:39 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	died(t_philos *philo, t_time start)
{
	t_time	end;

	gettimeofday(&end, NULL);
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

void	print_action(t_philos *philo, char *msg, t_time start, t_time end)
{
	pthread_mutex_lock(&philo->data->write);
	if (philo->data->alive == 0)
	{
		pthread_mutex_unlock(&philo->data->write);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		return ;
	}
	printf("%ld %d %s", set_time(start, end), philo->id_philo, msg);
	pthread_mutex_unlock(&philo->data->write);
}

void	taken_fork(t_philos *philo, t_time start)
{
	if (philo->id_philo % 2 == 0)
		even_behavior(philo, start);
	else
	{
		usleep(1000);
		odd_behavior(philo, start);
	}
	died(philo, start);
}

void	eating(t_philos *philo, t_time start)
{
	t_time	end;

	gettimeofday(&end, NULL);
	print_action(philo, "is eating\n", start, end);
	gettimeofday(&(philo->last_meal_time), NULL);
	usleep(1000 * philo->data->eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	sleeping_thinking(t_philos *philo, t_time start)
{
	t_time	end;

	gettimeofday(&end, NULL);
	print_action(philo, "is sleeping\n", start, end);
	usleep(1000 * philo->data->sleep);
	gettimeofday(&end, NULL);
	print_action(philo, "is thinking\n", start, end);
}
