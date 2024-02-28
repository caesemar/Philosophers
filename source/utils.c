/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:18:49 by jocasado          #+#    #+#             */
/*   Updated: 2024/02/28 20:10:20 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

static int	espacios(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			i++;
			return (-i);
		}
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	j;
	int				signo;

	signo = 1;
	j = 0;
	i = espacios (str);
	if (i < 0)
	{
		i = -i;
		signo = -1;
	}
	while (str[i] != 0 && (str[i] >= '0' && str[i] <= '9'))
	{
		j = j * 10 + (str[i] - '0');
		i++;
	}
	if (j > LONG_MAX && signo == 1)
		return (-1);
	if (j > LONG_MAX && signo == -1)
		return (0);
	if (signo == -1)
		return (-j);
	return (j);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	i = 0;
	s3 = (unsigned char *) s1;
	s4 = (unsigned char *) s2;
	while ((i < n) && (s3[i] != '\0' || s4[i] != '\0'))
	{
		if (s3[i] > s4[i])
			return (s3[i] - s4[i]);
		if (s3[i] < s4[i])
			return (s3[i] - s4[i]);
		i++;
	}
	return (0);
}
