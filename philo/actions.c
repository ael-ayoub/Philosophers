/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:45:56 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/03 06:19:19 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_action(t_thread *philo, char *msg)
{
	t_time	end;

	pthread_mutex_lock(philo->data->write);
	if (philo->data->alive == 0)
	{
		pthread_mutex_unlock(philo->data->write);
		return ;
	}
	gettimeofday(&end, NULL);
	printf("%ld %d %s", set_time(philo->data->start, end), philo->index, msg);
	pthread_mutex_unlock(philo->data->write);
}

void	taken_fork(t_thread *philo)
{
	if (philo->index % 2 == 0)
		even_behavior(philo);
	else
	{
		usleep(100);
		odd_behavior(philo);
	}
}

void	eating(t_thread *philo)
{
	print_action(philo, "is eating\n");
	pthread_mutex_lock(philo->data->write);
	gettimeofday(&(philo->last_meal_time), NULL);
	pthread_mutex_unlock(philo->data->write);
	usleep(1000 * philo->data->eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	sleeping_thinking(t_thread *philo)
{
	print_action(philo, "is sleeping\n");
	usleep(1000 * philo->data->sleep);
	print_action(philo, "is thinking\n");
}
