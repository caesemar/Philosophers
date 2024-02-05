/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:36:29 by jocasado          #+#    #+#             */
/*   Updated: 2024/02/05 02:31:06 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

void	*life_actions(void *philo)
{
	t_philo	*philosopher;
	//printf("hola3\n");
	philosopher = (t_philo *)philo;
	philosopher->t_from_last_meal = get_current_time();
	while (philosopher->philo_eat_count > 0 && \
		!lock_stop(philosopher->values))
	{
		if (philosopher->status != DEAD)
			death(philosopher);
		else if (philosopher->status == THINK)
			eat(philosopher);
		else if (philosopher->status == EAT)
			sleep_action(philosopher);
		else if (philosopher->status == SLEEP)
			think(philosopher);
	}
	return (NULL);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	philo->status = SLEEP;
	philo->t_from_last_meal = get_current_time() + philo->t_from_last_meal;
	philo->philo_eat_count--;
	ft_usleep(philo->values->time_to_eat);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_actions(philo);
	if (philo->philo_eat_count == 0)
	{
		philo->status = DEAD;
		print_actions(philo);
	}
}

void	think(t_philo *philo)
{
	philo->status = EAT;
	ft_usleep(philo->values->time_to_sleep);
	print_actions(philo);
}

void	sleep_action(t_philo *philo)
{
	philo->status = THINK;
	ft_usleep(philo->values->time_to_sleep);
	print_actions(philo);
}

void	death(t_philo *philo)
{
	if (get_current_time() - philo->t_from_last_meal > \
		(size_t)philo->values->time_to_die)
	{
		philo->status = DEAD;
		print_actions(philo);
	}
}
