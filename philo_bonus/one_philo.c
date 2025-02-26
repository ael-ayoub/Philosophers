/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:30:04 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 11:35:08 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	one_philo_1(t_philos *philo, t_time start)
{
	t_time	end;

	gettimeofday(&end, NULL);
	sem_wait(philo->data->write);
	printf("%ld %d has taken a fork\n", set_time(start, end), philo->id_philo);
	printf("%ld %d died\n", set_time(start, end), philo->id_philo);
	sem_post(philo->data->alive);
}

void	one_philo_2(t_philos *philo, t_time start)
{
	t_time	end;

	gettimeofday(&end, NULL);
	sem_wait(philo->data->write);
	printf("%ld %d has taken a fork\n", set_time(start, end), philo->id_philo);
	printf("%ld %d died\n", set_time(start, end), philo->id_philo);
	sem_post(philo->data->count);
}
