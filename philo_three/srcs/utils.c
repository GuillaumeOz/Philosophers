/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:18:28 by user42            #+#    #+#             */
/*   Updated: 2020/12/07 18:54:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

size_t		ft_strlen(char *str)
{
	size_t  len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int			ft_atoi_philo(char *str, t_state *state)
{
	int			i;
	int			nb;

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

bool		ft_is_digit(char c)
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

