/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_odd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:30:32 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/03 02:23:03 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	even_behavior(t_thread *philo)
{
	pthread_mutex_lock(philo->right);
	print_action(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->left);
	print_action(philo, "has taken a fork\n");
}

void	odd_behavior(t_thread *philo)
{
	pthread_mutex_lock(philo->left);
	print_action(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->right);
	print_action(philo, "has taken a fork\n");
}
