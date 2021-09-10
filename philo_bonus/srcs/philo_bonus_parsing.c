/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:12:46 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/07 07:51:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	parse_philo(char *arg, t_state *state)
{
	int	nb_philo;
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (ft_is_digit(arg[i]) == false)
		{
			error_msg("Forbidden char detected in Number of philosopher");
			state->error_state = true;
			return ;
		}
	}
	if (ft_strlen(arg) > 3 || ft_atoi_philo(arg, state) <= 1)
	{
		error_msg("Number of philosopher is too big or too small");
		state->error_state = true;
		return ;
	}
	nb_philo = ft_atoi_philo(arg, state);
	set_state_nb_philo_fork(state, nb_philo, PHILO);
	set_state_nb_philo_fork(state, nb_philo, FORK);
	return ;
}

void	parse_time_to_die(char *arg, t_state *state)
{
	int	time_to_die;
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (ft_is_digit(arg[i]) == false)
		{
			error_msg("Forbidden char detected in time to die");
			state->error_state = true;
			return ;
		}
	}
	if (ft_strlen(arg) > 9)
	{
		error_msg("Time to die is too big");
		state->error_state = true;
		return ;
	}
	time_to_die = ft_atoi_philo(arg, state);
	set_state_time_to_die(state, time_to_die);
	return ;
}

void	parse_time_to_eat(char *arg, t_state *state)
{
	int	time_to_eat;
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (ft_is_digit(arg[i]) == false)
		{
			error_msg("Forbidden char detected in time to eat");
			state->error_state = true;
			return ;
		}
	}
	if (ft_strlen(arg) > 9)
	{
		error_msg("Time to eat is too big");
		state->error_state = true;
		return ;
	}
	time_to_eat = ft_atoi_philo(arg, state);
	set_state_time_to_eat(state, time_to_eat);
	return ;
}

void	parse_time_to_sleep(char *arg, t_state *state)
{
	int	time_to_sleep;
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (ft_is_digit(arg[i]) == false)
		{
			error_msg("Forbidden char detected in time to sleep");
			state->error_state = true;
			return ;
		}
	}
	if (ft_strlen(arg) > 9)
	{
		error_msg("Time to sleep is too big");
		state->error_state = true;
		return ;
	}
	time_to_sleep = ft_atoi_philo(arg, state);
	set_state_time_to_sleep(state, time_to_sleep);
	return ;
}

void	parse_nb_time_to_eat(char *arg, t_state *state)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (ft_is_digit(arg[i]) == false)
		{
			error_msg("Forbidden char detected in number time to eat");
			state->error_state = true;
			return ;
		}
	}
	if (ft_strlen(arg) > 9)
	{
		error_msg("Number time to eat is too big");
		state->error_state = true;
		return ;
	}
	set_state_nb_time_to_eat(state, ft_atoi_philo(arg, state));
}
