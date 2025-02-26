/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:43:57 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 11:48:41 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	validate_args(int ac, char *av[], t_data *data)
{
	if (ac != 5 && ac != 6)
	{
		printf("invalid syntax.\n");
		return (0);
	}
	if (!init_data(data, av, ac))
	{
		printf("invalid arguments.\n");
		return (0);
	}
	return (1);
}

void	kill_processes(t_philos *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_p)
	{
		if (philo[i].id_process > 0)
			kill(philo[i].id_process, SIGKILL);
		i++;
	}
}

int	initialize_simulation(int ac, char *av[], t_philos **philos, t_data *data)
{
	if (!validate_args(ac, av, data))
		return (0);
	*philos = init_process(data);
	if (!(*philos))
	{
		printf("error in initialization of thread\n");
		return (0);
	}
	return (1);
}

t_philos	*init_process(t_data *data)
{
	int			i;
	t_philos	*process;

	process = (t_philos *)malloc(sizeof(t_philos) * data->nbr_p);
	if (!process)
		return (NULL);
	i = 0;
	while (i < data->nbr_p)
	{
		process[i].data = data;
		process[i].id_philo = i + 1;
		process[i].number_eat = 0;
		i++;
	}
	return (process);
}
