/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:28:40 by jocasado          #+#    #+#             */
/*   Updated: 2024/01/28 18:23:44 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

int	ft_overflow(char *temp1)
{
	char	*temp;
	int		i;

	i = 0;
	if (temp1[0] == '+')
		temp1++;
	while ((*temp1 == '0') && *(temp1 + 1) != 0)
	{
		temp1++;
		i++;
	}
	temp = ft_itoa(ft_atoi(temp1));
	if (ft_strncmp(temp1, temp, ft_strlen(temp)) == 0)
	{
		free(temp);
		return (0);
	}
	free (temp);
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_digit_comparation(char **a, int i, int j, int sign)
{
	if ((ft_isdigit(a[i][j])) || a[i][j] == ' '
			|| ((a[i][j] == '+' || a[i][j] == '-') \
				&& (ft_isdigit(a[i][j + 1]) && sign == 1)))
		return (1);
	return (0);
}

int	ft_error_check(char **a)
{
	int	i;
	int	j;
	int	sign;

	j = 0;
	i = 1;
	while (a[i])
	{
		sign = 1;
		while (a[i][j])
		{
			if (ft_digit_comparation(a, i, j, sign))
				j++;
			else
				return (1);
			if (a[i][j - 1] == '+' || a[i][j - 1] == '-' ||
						ft_isdigit(a[i][j - 1]))
				sign = 0;
			if (a[i][j - 1] == ' ')
				sign = 1;
		}
		j = 0;
		i++;
	}
	return (0);
}
