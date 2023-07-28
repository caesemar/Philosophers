/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:18:27 by jocasado          #+#    #+#             */
/*   Updated: 2023/07/28 15:18:27 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

int	main(int argc, char **argv)
{
	t_philosopher	philo;

	parse_args(&philo, argc, argv);
	return (0);
}

void	parse_args(t_philosopher *philo, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		exit (0);
	}
	ft_error_check (argv);
	while (++i < argc)
	{
		if (ft_overflow(argv[i]) == 1)
			ft_error2();
	}
	is_positive(argv, argc);
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		philo->number_of_times_each_philosopher_must_eat = -1;
}
