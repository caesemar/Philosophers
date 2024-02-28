/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:28:27 by jocasado          #+#    #+#             */
/*   Updated: 2024/02/28 18:41:48 by jocasado         ###   ########.fr       */
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

void	wait_threads(t_philo *ph, int nbr_philos)
{
	int	i;

	i = -1;
	while (++i < nbr_philos)
		pthread_join(ph[i].thread, NULL);
	i = -1;
	while (++i < nbr_philos)
		pthread_mutex_destroy(&ph[i].left_fork);
	pthread_mutex_destroy(&ph[0].values->m_print);
	pthread_mutex_destroy(&ph[0].values->m_dead);
	pthread_mutex_destroy(&ph[0].values->meal_lock);
	free(ph);
}
