/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:52:07 by zpalfi            #+#    #+#             */
/*   Updated: 2022/04/08 14:37:45 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	free(data->philo);
	while (++i < data->n_philo)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->is_writing);
	free(data->forks);
	free(data);
}
