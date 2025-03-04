/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:30:04 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/02 03:04:01 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	one_philo(t_process *philo, t_time start)
{
	t_time	end;

	sem_wait(philo->data->lock);
	gettimeofday(&end, NULL);
	printf("%ld %d has taken a fork\n", set_time(start, end), philo->id);
	printf("%ld %d died\n", set_time(start, end), philo->id);
	sem_post(philo->data->lock);
	if (philo->data->option_arg == -1)
		sem_wait(philo->data->alive);
	else
		sem_wait(philo->data->count);
}
