/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:55:46 by jocasado          #+#    #+#             */
/*   Updated: 2024/02/22 19:59:27 by jocasado         ###   ########.fr       */
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
void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(&philo->values->m_print);
	time = get_current_time() - philo->start_time;
	//if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(&philo->values->m_print);
}
