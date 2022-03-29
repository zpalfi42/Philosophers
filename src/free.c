/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:52:07 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/29 13:14:35 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = data->n_philo;
	while (--i)
	{
		pthread_mutex_unlock(&data->forks[i]);
		pthread_mutex_destroy(&data->forks[i]);
	}
	free(data->forks);
	free(data);
}
