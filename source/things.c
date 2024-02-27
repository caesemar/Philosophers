/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   things.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:49:47 by jocasado          #+#    #+#             */
/*   Updated: 2024/02/28 00:49:02 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

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
