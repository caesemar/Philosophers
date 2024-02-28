/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:19:15 by jocasado          #+#    #+#             */
/*   Updated: 2024/02/28 00:57:41 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# define THINK 0
# define SLEEP 1
# define EAT 2
# define DEAD -1

typedef struct s_init
{
	int					phil_num;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					eat_counter;
	int					stop;
	pthread_mutex_t		m_print;
	pthread_mutex_t		m_dead;
	pthread_mutex_t		meal_lock;
}	t_init;

typedef struct s_philo
{
	pthread_t			thread;
	int					id_philo;
	int					stop;
	int					status;
	size_t				start_time;
	size_t				t_from_last_meal;
	int					philo_eat_count;
	int					*right_fork_value;
	int					left_fork_value;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*meal_lock;
	t_init				*values;
}	t_philo;

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		parse_args(t_init *philo, int argc, char **argv);
int		ft_isdigit(int c);
int		ft_overflow(char *temp1);
int		ft_error_check(char **a);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
int		is_positive(char **argv, int argc);
int		ft_atoi(const char *str);
int		init_threads(t_init values, t_philo *philosophers);
int		init_philos(t_init *values, t_philo *philo);
void	*life_actions(void *philo);
void	init_initvalues(t_init *init, int argc, char **argv);
size_t	get_current_time(void);
int		ft_usleep(size_t miliseconds);
int		error_on_threads(t_philo *philosophers, int i);
int		init_forks(t_philo *ph, int nbr_philos);
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	sleep_action(t_philo *philo);
int		death(t_philo *philo);
void	print_message(char *str, t_philo *philo, int id);
void	free_all(t_philo *philosophers);
int		init_mutex(t_philo *ph, t_init *init);
int		lock_stop(t_init *init);
void	*detect_death(void *pointer);
void	wait_threads(t_philo *ph, int nbr_philos);

#endif
