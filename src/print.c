/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:11:17 by zpalfi            #+#    #+#             */
/*   Updated: 2022/04/05 17:25:08 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->data->is_writing);
	printf("[%lld]	philosopher [%d] %s\n", (get_time()
			- philo->data->init_time), philo->id, s);
	pthread_mutex_unlock(&philo->data->is_writing);
}
