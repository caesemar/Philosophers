/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:55:46 by jocasado          #+#    #+#             */
/*   Updated: 2024/02/28 01:51:22 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(&philo->values->m_print);
	time = get_current_time() - philo->start_time;
	if (!death(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(&philo->values->m_print);
}

static int	check_philosopher_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->t_from_last_meal >= time_to_die
		&& philo->status != EAT)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

static int	check_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].values->phil_num)
	{
		if (check_philosopher_dead(&philos[i], philos[i].values->time_to_die))
		{
			print_message("died", &philos[i], philos[i].id_philo);
			pthread_mutex_lock(&philos[0].values->m_dead);
			philos[0].values->stop = 1;
			pthread_mutex_unlock(&philos[0].values->m_dead);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_all_ate(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].values->eat_counter == -1)
		return (0);
	while (i < philos[0].values->phil_num)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].philo_eat_count >= philos[0].values->eat_counter)
			finished_eating++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finished_eating == philos[0].values->phil_num)
	{
		pthread_mutex_lock(&philos[0].values->m_dead);
		philos[0].values->stop = 1;
		pthread_mutex_unlock(&philos[0].values->m_dead);
		return (1);
	}
	return (0);
}

void	*detect_death(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
	while (1)
	{
		if (check_dead(philos) == 1 || check_all_ate(philos) == 1)
			break ;
	}
	return (pointer);
}
