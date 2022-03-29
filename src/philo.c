/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:24:31 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/29 13:43:39 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_nit(t_data *data)
{
	int	i;
	
	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		return (0);
	while (i < data->n_philo - 1)
	{
		data->philo[i].id = i;
		data->philo[i].rf = i;
		data->philo[i].lf = i + 1;
	}
	data->philo[i].id = i;
	data->philo[i].rf = i;
	data->philo[i].lf = 0;
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
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->n_eat = ft_atoi(argv[5]);
		if (data->n_eat < 1)
			return (0);
	}
	else
		data->n_eat = -1;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
		return (error("Invalid number of arguments"));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data || !data_init(data, argc, argv))
		return (error("Failed data init"));
	if (!forks_init(data) || philo_init(data))
		return (error("Failed threads init"));
	routine_init(data);
	free_data(data);
}
