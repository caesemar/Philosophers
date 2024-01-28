/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:36:35 by jocasado          #+#    #+#             */
/*   Updated: 2024/01/28 23:20:47 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"


void	init_philos(t_init values, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < values.phil_num)
	{
		*philo[i]->id_philo = i;
		*philo[i]->status = THINK;
		*philo[i]->philo_eat_count = 0;
		*philo[i]->start_time = 0;
		i++;
	}
	init_threads(values, philo);
}

int	init_threads(t_init values, t_philo **philosophers)
{
	int	i;

	i = 0;
	while (i < values.phil_num)
	{
		if (pthread_create(&philosophers[i].thread, NULL, \
	&life_actions, &philosophers[i]))
		{	
			printf("Error creating threads");
			return (1);
		}
		i = i + 2;
	}
	usleep(50);
	i = 1;
	while (i < values.phil_num)
	{
		if (pthread_create(&philosophers[i].thread, NULL, \
	&life_actions, &philosophers[i]))
		{	
			printf("Error creating threads");
			return (1);
		}
		i = i + 2;
	}
}

