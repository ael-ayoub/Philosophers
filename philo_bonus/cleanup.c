/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:06:27 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 11:52:36 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	cleanup(t_philos *philos, t_data *data)
{
	if (data->write)
		sem_close(data->write);
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
	sem_unlink("alive");
	sem_unlink("write");
	sem_unlink("forks");
	sem_unlink("counter");
	sem_unlink("mutex_fork");
	free(philos);
}

void	cleanup_child(t_philos *philos, t_data *data)
{
	if (data->write)
		sem_close(data->write);
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
	free(philos);
}
