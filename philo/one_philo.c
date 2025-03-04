/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:09:51 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/03 02:23:03 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	one_philo(t_thread *philo)
{
	printf("0 %d has taken a fork\n", philo->index);
	printf("0 %d died\n", philo->index);
	philo->data->alive = 0;
}
