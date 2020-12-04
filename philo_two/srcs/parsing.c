/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:12:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/02 13:52:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	parse_philo(char *arg, t_state *state)
{
	int	nb_philo;
	int	i;

	i = -1;
	while (arg[++i])
		if (ft_is_digit(arg[i]) == false)
		{
			error_msg("Forbidden char detected in Number of philosopher");
			state->error_state = true;
			return ;
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
		if (ft_is_digit(arg[i]) == false)
		{
			error_msg("Forbidden char detected in time to die");
			state->error_state = true;
			return ;
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
		if (ft_is_digit(arg[i]) == false)
		{
			error_msg("Forbidden char detected in time to eat");
			state->error_state = true;
			return ;
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
		if (ft_is_digit(arg[i]) == false)
		{
			error_msg("Forbidden char detected in time to sleep");
			state->error_state = true;
			return ;
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
	int	nb_time_to_eat;
	int	i;

	i = 0;
	if (arg[0] != '[' || arg[(size_t)ft_strlen(arg) - 1] != ']')
	{
		error_msg("'[' or ']' is missing around number time to eat");
		state->error_state = true;
		return ;
	}
	while (arg[++i] && i < (int)(ft_strlen(arg) - 1))
		if (ft_is_digit(arg[i]) == false)
		{
			error_msg("Forbidden char detected in number time to eat");
			state->error_state = true;
			return ;
		}
	if (ft_strlen(arg) > 9 || ft_strlen(arg) <= 2)
	{
		error_msg("Number time to eat is too big or too short");
		state->error_state = true;
		return ;
	}
	nb_time_to_eat = ft_atoi_philo(arg + 1, state);
	set_state_nb_time_to_eat(state, nb_time_to_eat);
	return ;
}
