/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_odd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:30:32 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 09:31:34 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	take_fork(t_time start, t_philos *philo, pthread_mutex_t *fork,
		char *msg)
{
	t_time	end;

	pthread_mutex_lock(fork);
	gettimeofday(&end, NULL);
	if (!died(philo, start, end))
		return ;
	pthread_mutex_lock(&philo->data->write);
	if (philo->data->alive == 0)
	{
		pthread_mutex_unlock(&philo->data->write);
		pthread_mutex_unlock(fork);
		return ;
	}
	printf("%ld %d %s", set_time(start, end), philo->id_philo, msg);
	pthread_mutex_unlock(&philo->data->write);
}

void	even_odd(t_time start, t_philos *philo)
{
	if (philo->id_philo % 2 == 0)
	{
		take_fork(start, philo, philo->right, "has taken a fork\n");
		take_fork(start, philo, philo->left, "has taken a fork\n");
	}
	else
	{
		take_fork(start, philo, philo->left, "has taken a fork\n");
		take_fork(start, philo, philo->right, "has taken a fork\n");
	}
}
