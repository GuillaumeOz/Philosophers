/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:18:28 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 18:38:58 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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

void	ft_putnbr(unsigned long nb)
{
	long i;

	i = nb;
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		write(1, i + '0', 1);
}

void		ft_philo_msg(t_philo *philo, char *msg)
{
	char	buff[100];
	t_state *state;
	t_time	*time;

	state = get_philo_state_addr(philo);
	time = get_philo_time_addr(philo);


}
