/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:36:18 by zpalfi            #+#    #+#             */
/*   Updated: 2022/04/08 12:28:39 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				rf;
	int				lf;
	int				dead;
	int				n_eat;
	long long int	last_eat;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				all_eat;
	int				dead;
	long long int	init_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	is_writing;
	pthread_mutex_t	mdead;
}	t_data;

int				is_n(char *s);
int				ft_error(char *s);
int				check_argv(char **argv);
int				forks_init(t_data *data);
int				philo_init(t_data *data);
int				data_init(t_data *data, int argc, char **argv);

long long int	get_time(void);
long long int	ft_atoi(const char *str);

void			time_sleep(int i);
void			*routine(void *param);
void			free_data(t_data *data);
void			print_action(t_philo *philo, char *s);

#endif
