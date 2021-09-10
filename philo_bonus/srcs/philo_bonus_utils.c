/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:18:28 by user42            #+#    #+#             */
/*   Updated: 2021/09/06 23:35:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_atoi_philo(char *str, t_state *state)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (str[i] == '\0')
	{
		error_msg("An argument is empty");
		state->error_state = true;
		return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
	return (nb);
}

bool	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

void	ft_putnbr(unsigned long nb, char *buff, size_t *i)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, buff, i);
		ft_putnbr(nb % 10, buff, i);
	}
	else
		buff[++(*i)] = nb + '0';
}

bool	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (false);
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	return (true);
}
