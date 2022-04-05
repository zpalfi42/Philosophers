/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:35:06 by zpalfi            #+#    #+#             */
/*   Updated: 2022/04/05 17:43:03 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_simulation(t_data *data)
{
	int			i;
	pthread_t	*thread;

	i = -1;
	thread = (pthread_t *)malloc(sizeof(pthread_t) * data->n_philo);
	if (!thread)
		return (ft_error("Failed thread malloc"));
	data->init_time = get_time();
	while (++i < data->n_philo)
		pthread_create(&thread[i], NULL, &routine, (void *)(&data->philo[i]));
	i = -1;
	while (thread[++i])
		pthread_join(thread[i], NULL);
	free(thread);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
		return (ft_error("Invalid number of arguments"));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data || !data_init(data, argc, argv))
		return (ft_error("Failed data init"));
	if (!forks_init(data) || !philo_init(data))
		return (ft_error("Failed threads init"));
	init_simulation(data);
	free_data(data);
}
