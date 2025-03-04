/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:43:57 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/02 23:17:41 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	wait_for_processes(t_data *data)
{
	while (1)
	{
		if (data->count->__align == 0)
			break ;
	}
}

void	kill_processes(t_process *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->number)
	{
		if (philo[i].id > 0)
		{
			kill(philo[i].id, SIGKILL);
		}
		i++;
	}
}

int	create_processes(t_process *philos)
{
	int	i;
	int	number;

	number = philos->data->number;
	i = 0;
	gettimeofday(&philos[i].data->start, NULL);
	while (i < number)
	{
		philos[i].id = fork();
		if (philos[i].id < 0)
			return (0);
		if (philos[i].id == 0)
		{
			simulation(&philos[i]);
			cleanup_child(&philos[i]);
			exit(0);
		}
		i++;
	}
	return (1);
}
