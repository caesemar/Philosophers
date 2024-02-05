/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:36:35 by jocasado          #+#    #+#             */
/*   Updated: 2024/02/05 02:31:19 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

int	init_philos(t_init values, t_philo *philo)
{
	int	i;
	//printf("hola\n");
	if (init_mutex(philo, &values) == 1)
		return (1);
	i = -1;
	while (++i < values.phil_num)
	{
		philo[i].id_philo = i + 1;
		philo[i].status = THINK;
		philo[i].philo_eat_count = values.eat_counter;
	}
	init_forks(philo, values.phil_num);
	if (init_threads(values, philo) == 1)
	{
		printf("Error on threads initialization\n");
		return (1);
	}
	//printf ("hola2\n");
	return (0);
}

int	init_threads(t_init values, t_philo *philosophers)
{
	int	i;

	i = 0;
	while (i < values.phil_num)
	{
		if (pthread_create(&philosophers[i].thread, NULL, \
		&life_actions, &philosophers[i]))
			return (1);
		i = i + 2;
	}
	usleep(50);
	i = 1;
	while (i < values.phil_num)
	{
		if (pthread_create(&philosophers[i].thread, NULL, \
		&life_actions, &philosophers[i]))
			return (1);
		i = i + 2;
	}
	return (0);
}

int	init_forks(t_philo *ph, int phil_num)
{
	int	id_right;
	int	i;

	i = 0;
	while (i < phil_num)
	{
		if (i == phil_num - 1)
			id_right = 0;
		else
			id_right = i + 1;
		ph[i].right_fork_value = &ph[id_right].left_fork_value;
		ph[i].right_fork = &ph[id_right].left_fork;
		i++;
	}
	return (0);
}

int	init_mutex(t_philo *ph, t_init *init)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&init->m_print, NULL))
	{
		printf("Mutex init failed\n");
		return (1);
	}
	if (pthread_mutex_init(&init->m_stop, NULL))
	{
		printf("Mutex init failed\n");
		return (1);
	}
	while (++i < init->phil_num)
	{
		if (pthread_mutex_init(&ph[i].left_fork, NULL))
		{
			printf("Mutex init failed on forks\n");
			return (1);
		}
	}
	return (0);
}
