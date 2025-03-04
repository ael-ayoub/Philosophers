/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:06:27 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/02 03:21:20 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	cleanup(t_process *philos, t_data *data)
{
	if (data->lock)
		sem_close(data->lock);
	if (data->alive)
		sem_close(data->alive);
	if (data->forks)
		sem_close(data->forks);
	if (data->mutex_fork)
		sem_close(data->mutex_fork);
	if (data->count)
	{
		sem_close(data->count);
	}
	sem_unlink("/alive");
	sem_unlink("lock");
	sem_unlink("forks");
	sem_unlink("counter");
	sem_unlink("mutex_fork");
	free(philos);
}

void	cleanup_child(t_process *philos)
{
	if (philos->data->lock)
		sem_close(philos->data->lock);
	if (philos->data->forks)
		sem_close(philos->data->forks);
	if (philos->data->mutex_fork)
		sem_close(philos->data->mutex_fork);
	if (philos->data->count)
	{
		sem_close(philos->data->count);
	}
}
