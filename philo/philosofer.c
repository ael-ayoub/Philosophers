/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:33:45 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/25 16:33:46 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	validate_args(int ac, char *av[], t_data *data)
{
	if (ac != 5 && ac != 6)
	{
		printf("invalid syntax.\n");
		return (0);
	}
	if (ac == 5)
	{
		if (!init_data_1(data, av))
		{
			printf("invalid arguments.\n");
			return (0);
		}
	}
	else if (!init_data_2(data, av))
	{
		printf("invalid arguments.\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_philos	*philos;
	t_data		data;

	if (!validate_args(ac, av, &data))
		return (0);
	philos = init_threads(&data);
	if (!philos)
	{
		printf("Error in initialisation of threads\n");
		return (0);
	}
	if (!create_threads(&data, philos))
	{
		cleanup(&data, philos);
		return (0);
	}
	join_threads(&data, philos);
	cleanup(&data, philos);
	return (0);
}
