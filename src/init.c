/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:05:37 by zpalfi            #+#    #+#             */
/*   Updated: 2022/04/08 14:37:54 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_init(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		return (0);
	while (i < data->n_philo - 1)
	{
		data->philo[i].id = i + 1;
		data->philo[i].rf = i;
		data->philo[i].lf = i + 1;
		data->philo[i].dead = 0;
		data->philo[i].n_eat = data->n_eat;
		data->philo[i].data = data;
		i++;
	}
	data->philo[i].id = i + 1;
	data->philo[i].rf = i;
	data->philo[i].lf = 0;
	data->philo[i].dead = 0;
	data->philo[i].n_eat = data->n_eat;
	data->philo[i].data = data;
	return (1);
}

int	forks_init(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (0);
	i = 0;
	while (i++ < data->n_philo)
		if (pthread_mutex_init(&data->forks[i - 1], NULL) != 0)
			return (0);
	return (1);
}

int	data_init(t_data *data, int argc, char **argv)
{
	if (!check_argv(argv))
		return (0);
	data->n_philo = ft_atoi(argv[1]);
	if (data->n_philo < 1)
		return (0);
	data->n_eat = -1;
	if (argc == 6)
	{
		data->n_eat += ft_atoi(argv[5]) + 1;
		if (data->n_eat < 1)
			return (0);
	}
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->all_eat = 0;
	data->dead = 0;
	pthread_mutex_init(&data->is_writing, NULL);
	pthread_mutex_init(&data->mdead, NULL);
	return (1);
}
