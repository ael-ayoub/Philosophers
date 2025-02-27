/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_odd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:30:32 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/27 09:48:07 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	even_behavior(t_philos *philo, t_time start)
{
	t_time	end;

	pthread_mutex_lock(philo->right);
	gettimeofday(&end, NULL);
	print_action(philo, "has taken a fork\n", start, end);
	pthread_mutex_lock(philo->left);
	gettimeofday(&end, NULL);
	print_action(philo, "has taken a fork\n", start, end);
}

void	odd_behavior(t_philos *philo, t_time start)
{
	t_time	end;

	pthread_mutex_lock(philo->left);
	gettimeofday(&end, NULL);
	print_action(philo, "has taken a fork\n", start, end);
	pthread_mutex_lock(philo->right);
	gettimeofday(&end, NULL);
	print_action(philo, "has taken a fork\n", start, end);
}
