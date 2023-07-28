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
