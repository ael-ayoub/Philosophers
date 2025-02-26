/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:01:08 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 00:02:58 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

time_t	set_time(t_time start, t_time end)
{
	time_t	sec;
	time_t	usec;
	time_t	msec;

	sec = end.tv_sec - start.tv_sec;
	usec = end.tv_usec - start.tv_usec;
	if (usec < 0)
	{
		sec -= 1;
		usec += 1000000;
	}
	msec = sec * 1000 + usec / 1000;
	return (msec);
}

int	init_time_1(char **av, t_data *data)
{
	time_t	temp;

	temp = ft_atoi(av[1]);
	if (temp > INT_MAX || temp <= 0)
		return (0);
	data->nbr_p = (int)temp;
	temp = ft_atoi(av[2]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->die = temp;
	temp = ft_atoi(av[3]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->eat = temp;
	temp = ft_atoi(av[4]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->sleep = temp;
	data->option_arg = -1;
	return (1);
}

int	init_time_2(char **av, t_data *data)
{
	time_t	temp;

	temp = ft_atoi(av[1]);
	if (temp > INT_MAX || temp <= 0)
		return (0);
	data->nbr_p = (int)temp;
	temp = ft_atoi(av[2]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->die = temp;
	temp = ft_atoi(av[3]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->eat = temp;
	temp = ft_atoi(av[4]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->sleep = temp;
	temp = ft_atoi(av[5]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->option_arg = (int)temp;
	return (1);
}
