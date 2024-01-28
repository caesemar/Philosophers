/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initsophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:18:27 by jocasado          #+#    #+#             */
/*   Updated: 2023/11/11 21:03:26 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

int	main(int argc, char **argv)
{
	t_init	init;
	t_philo	philosophers;

	if (parse_args(&init, argc, argv) == 1)
	{
		printf ("Error on parse\n");
		return (1);
	}
	print_philo(&init);
	philosophers = NULL;
	philosophers = (t_philo *) malloc(sizeof(t_philo) * init.phil_num);
	if (philosophers == NULL)
	{
		printf("Error on malloc initialization\n");
		return (1);
	}
	if (init_philos(init, &philosophers))
		return (1);
	return (0);
}

int	parse_args(t_init *init, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (ft_error_check (argv))
		return (1);
	while (++i < argc)
	{
		if (ft_overflow(argv[i]) == 1)
			return (1);
	}
	if (is_positive(argv, argc) == 1)
		return (1);
	init_initvalues(init, argc, argv);
	return (0);
}

void	init_initvalues(t_init *init, int argc, char **argv)
{
	init->number_of_philosophers = ft_atoi(argv[1]);
	init->time_to_die = ft_atoi(argv[2]);
	init->time_to_eat = ft_atoi(argv[3]);
	init->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		init->eat_counter = ft_atoi(argv[5]);
	else
		init->eat_counter = -1;
}
