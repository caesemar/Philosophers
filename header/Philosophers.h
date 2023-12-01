/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:19:15 by jocasado          #+#    #+#             */
/*   Updated: 2023/12/01 18:44:05 by jocasado         ###   ########.fr       */
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

/*
typedef struct table
{

};
*/
typedef struct s_init
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_init;

typedef struct s_philo
{
	pthread_t	*philosopher;
	int	time_until_death;
	int	time_eating;
	int	time_sleeping;
	int	time_til_full;
	int fork;
}	t_philo;

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	parse_args(t_init *philo, int argc, char **argv);
int		ft_isdigit(int c);
int		ft_overflow(char *temp1);
void	ft_error_check(char **a);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
void	is_positive(char **argv, int argc);
int		ft_atoi(const char *str);
void	ft_error2(void);
void	print_philo(t_init *philo);
void	init(t_philo *philo);

#endif
