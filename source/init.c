/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:36:35 by jocasado          #+#    #+#             */
/*   Updated: 2024/02/22 22:53:04 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

int	init_philos(t_init values, t_philo *philo)
{
	int	i;
	if (init_mutex(philo, &values) == 1)
		return (1);
	i = -1;
	while (++i < values.phil_num)
	{
		philo[i].id_philo = i + 1;
		philo[i].start_time = get_current_time();
		philo[i].t_from_last_meal = get_current_time();
		philo[i].values = &values;
		philo[i].values->stop = 0;
		philo[i].status = THINK;
		philo[i].philo_eat_count = values.eat_counter;
	}
	printf("%i hola\n",philo[1].values->time_to_eat);
	if (init_forks(philo, values.phil_num) == 1)
		return (1);
	printf ("hola1\n");
	if (init_threads(values, philo) == 1)
		return (1);
	printf ("hola2\n");
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
	ft_usleep(50);
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
	if (pthread_mutex_init(&init->m_dead, NULL))
	{
		printf("Mutex init failed\n");
		return (1);
	}
	while (++i < init->phil_num)
	{
		if (pthread_mutex_init(&ph[i].left_fork, NULL) || \
		pthread_mutex_init(&ph[i].meal_lock, NULL))
		{
			printf("Mutex init failed \n");
			return (1);
		}
	}
	return (0);
}
