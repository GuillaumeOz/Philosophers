/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_t_state_setter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:51:06 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/01 00:32:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_state_nb_philo_fork(t_state *state, int value,
	t_state_option option)
{
	if (option == PHILO)
		state->nb_philo = value;
	if (option == FORK)
		state->nb_fork = value;
}

void	set_state_time_to_die(t_state *state, int value)
{
	state->time_to_die = value;
}

void	set_state_time_to_eat(t_state *state, int value)
{
	state->time_to_eat = value;
}

void	set_state_time_to_sleep(t_state *state, int value)
{
	state->time_to_sleep = value;
}

void	set_state_nb_time_to_eat(t_state *state, int value)
{
	state->nb_time_to_eat = value;
}
