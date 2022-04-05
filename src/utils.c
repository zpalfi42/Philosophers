/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:15:44 by zpalfi            #+#    #+#             */
/*   Updated: 2022/04/04 13:45:06 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

long long int	ft_atoi(const char *str)
{
	int				count;
	long long int	aux;

	count = 1;
	aux = 0;
	while (*str && (*str == ' ' || *str == '\f' || *str == '\n'
			|| *str == '\r' || *str == '\t' || *str == '\v'))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			count = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		aux = (aux * 10) + (*str - '0');
		str++;
	}
	aux = aux * count;
	return (aux);
}

int	is_n(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) || ft_atoi(s) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}
