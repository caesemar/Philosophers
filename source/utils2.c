/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:28:27 by jocasado          #+#    #+#             */
/*   Updated: 2024/02/22 19:17:40 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

int	is_positive(char **argv, int argc)
{
	int	i;

	i = 1;
	if (ft_atoi(argv[1]) <= 0)
		return (1);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (1);
		i++;
	}
	return (0);
}

void	print_philo(t_init *philo)
{
	printf("number_of_philosophers %d\n", philo->phil_num);
	printf("time_to_die %d\n", philo->time_to_die);
	printf("time_to_eat %d\n", philo->time_to_eat);
	printf("time_to_sleep %d\n", philo->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat %d\n", \
	philo->eat_counter);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t miliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < miliseconds)
		usleep(500);
	return (0);
}

int	lock_stop(t_init *init)
{
	int	stop;

	pthread_mutex_lock(&init->m_dead);
	stop = init->stop;
	pthread_mutex_unlock(&init->m_dead);
	return (stop);
}
