/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:36:29 by jocasado          #+#    #+#             */
/*   Updated: 2024/02/25 22:22:51 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

void	*life_actions(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id_philo % 2 == 0)
		ft_usleep(2);
	while (death(philo) == 0)
	{
		eat(philo);
		if (death(philo) == 1)
			break ;
		sleep_action(philo);
		if (death(philo) == 1)
			break ;
		think(philo);
	}
	return (pointer);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo, philo->id_philo);
	if (philo->values->phil_num == 1)
	{
		ft_usleep(philo->values->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(&philo->left_fork);
	print_message("has taken a fork", philo, philo->id_philo);
	philo->status = EAT;
	print_message("is eating", philo, philo->id_philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->t_from_last_meal = get_current_time();
	philo->philo_eat_count++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->values->time_to_eat);
	philo->status = SLEEP;
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	think(t_philo *philo)
{
	philo->status = THINK;
	print_message("is thinking", philo, philo->id_philo);
}

void	sleep_action(t_philo *philo)
{
	philo->status = SLEEP;
	print_message("is sleeping", philo, philo->id_philo);
	ft_usleep(philo->values->time_to_sleep);
}

int	death(t_philo *philo)
{
	pthread_mutex_lock(&philo->values->m_dead);
	if (philo->values->stop == 1)
	{
		pthread_mutex_unlock(&philo->values->m_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->values->m_dead);
	return (0);
}
