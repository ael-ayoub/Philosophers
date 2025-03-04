/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:30:33 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/01 22:59:01 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	ft_whitespace(char *str, int *i)
{
	int	sign;

	sign = 1;
	(*i) = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	check_digit(int i, char *str)
{
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi(char *str)
{
	long	nbr;
	int		i;
	int		sign;

	nbr = 0;
	if (!str)
		return ((long)INT_MAX + 1);
	sign = ft_whitespace(str, &i);
	if (!check_digit(i, str))
		return ((long)INT_MAX + 1);
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	nbr *= sign;
	return (nbr);
}
