/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:55:46 by jocasado          #+#    #+#             */
/*   Updated: 2024/02/05 02:24:05 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

/*
void	free_all(t_philo *philosophers)
{
	int	i;

	i = 0;
	while (i < philo->phil_num)
	{
		pthread_mutex_destroy(&philosophers[i].left_fork);
		pthread_mutex_destroy(philosophers[i].right_fork);
		pthread_mutex_destroy(philosophers[i]->print);
		pthread_mutex_destroy(philosophers[i]->stop);
		i++;
	}
	free(philosophers);
}
*/
void	print_actions(t_philo *philo)
{
	pthread_mutex_lock(&philo->values->m_print);
	if (philo->status == DEAD)
	{
		printf("%ld %d died\n", get_current_time() - philo->start_time, \
		philo->id_philo);
		pthread_mutex_unlock(&philo->values->m_print);
		return ;
	}
	if (philo->status == EAT)
		printf("%ld %d is eating\n", get_current_time() - philo->start_time, \
		philo->id_philo);
	if (philo->status == SLEEP)
		printf("%ld %d is sleeping\n", get_current_time() - philo->start_time, \
		philo->id_philo);
	if (philo->status == THINK)
		printf("%ld %d is thinking\n", get_current_time() - philo->start_time, \
		philo->id_philo);
	pthread_mutex_unlock(&philo->values->m_print);
}
