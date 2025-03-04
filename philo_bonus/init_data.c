/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:03:20 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/02 03:14:39 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	init_data(t_data *data, char **av, int ac)
{
	if (ac == 5)
	{
		if (!init_time_1(av, data))
			return (0);
	}
	else if (ac == 6)
	{
		if (!init_time_2(av, data))
			return (0);
	}
	sem_unlink("lock");
	sem_unlink("  alive");
	sem_unlink("forks");
	sem_unlink("counter");
	sem_unlink("mutex_fork");
	data->lock = sem_open("lock", O_CREAT, 0666, 1);
	data->alive = sem_open("/alive", O_CREAT, 0666, 1);
	data->forks = sem_open("forks", O_CREAT, 0666, data->number);
	data->count = sem_open("counter", O_CREAT, 0666, data->number);
	data->mutex_fork = sem_open("mutex_fork", O_CREAT, 0666, 1);
	return (1);
}
