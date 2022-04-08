/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:14:41 by zpalfi            #+#    #+#             */
/*   Updated: 2022/04/08 14:06:53 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->lf]);
	if (philo->data->dead)
		return (0);
	print_action(philo, "has taken a fork");
	if (philo->data->dead || philo->data->n_philo == 1)
		return (0);
	pthread_mutex_lock(&philo->data->forks[philo->rf]);
	if (philo->data->dead || philo->data->n_philo == 1)
		return (0);
	print_action(philo, "has taken a fork");
	philo->last_eat = get_time();
	if (philo->data->dead)
		return (0);
	print_action(philo, "is eating");
	time_sleep(philo->data->t_eat);
	philo->n_eat--;
	pthread_mutex_unlock(&philo->data->forks[philo->lf]);
	pthread_mutex_unlock(&philo->data->forks[philo->rf]);
	return (1);
}

static int	sleeping(t_philo *philo)
{
	if (philo->data->dead)
		return (0);
	print_action(philo, "is sleeping");
	time_sleep(philo->data->t_sleep);
	return (1);
}

static int	thinking(t_philo *philo)
{
	if (philo->data->dead)
		return (0);
	print_action(philo, "is thinking");
	return (1);
}

void	*routine(void *param)
{
	int	i;
//	pthread_t	dead_thread;
	t_philo		*philo;

	philo = (t_philo *)param;
//	printf("%d   %d\n", philo->id, philo->data->t_eat);
	if (philo->id % 2 == 0)
		time_sleep(200);
//	pthread_create(&dead_thread, NULL, &philo_dead, param);
	philo->last_eat = get_time();
//	printf("%lld AAAAA\n", get_time() - philo->last_eat);
	while (!philo->data->dead && philo->n_eat != 0)
	{
		if (philo->n_eat == 0)
			break ;
		if (!eating(philo))
			break ;
		if (!sleeping(philo))
			break ;
		if (!thinking(philo))
			break ;
	}
	i = 0;
	while (i < philo->data->n_philo)
	{
		pthread_mutex_unlock(&philo->data->forks[i]);
		i++;
	}
//	pthread_detach(dead_thread);
	return (NULL);
}
