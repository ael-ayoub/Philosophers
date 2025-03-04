/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:37:03 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/03 02:23:40 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cleanup(t_data *data, t_thread *thread, t_monitor *monitor)
{
	int	i;

	i = 0;
	while (i < data->number)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(data->write);
	free(monitor);
	free(data->forks);
	free(thread);
	free(data->write);
}
