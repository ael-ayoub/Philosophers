/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:17:09 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/01 22:42:36 by ael-aiss         ###   ########.fr       */
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

int	initialize_simulation(int ac, char *av[], t_process **philos, t_data *data)
{
	if (!validate_args(ac, av, data))
		return (0);
	*philos = init_process(data);
	if (!*philos)
	{
		printf("Error in the initialization of the process.\n");
		return (0);
	}
	return (1);
}

t_process	*init_process(t_data *data)
{
	int			i;
	t_process	*process;

	process = (t_process *)malloc(sizeof(t_process) * data->number);
	if (!process)
		return (NULL);
	i = 0;
	while (i < data->number)
	{
		process[i].data = data;
		process[i].index = i + 1;
		process[i].number_eat = 0;
		i++;
	}
	return (process);
}
