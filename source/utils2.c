/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:28:27 by jocasado          #+#    #+#             */
/*   Updated: 2023/07/28 18:28:27 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

void	is_positive(char **argv, int argc)
{
	int	i;

	i = 1;
	if (ft_atoi(argv[1]) <= 0)
		ft_error2();
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 0)
			ft_error2();
		i++;
	}
}

void	print_philo(t_philosopher *philo)
{
	printf("number_of_philosophers %d\n", philo->number_of_philosophers);
	printf("time_to_die %d\n", philo->time_to_die);
	printf("time_to_eat %d\n", philo->time_to_eat);
	printf("time_to_sleep %d\n", philo->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat %d\n", \
	philo->number_of_times_each_philosopher_must_eat);
}
