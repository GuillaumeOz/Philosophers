/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_state_getter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:50:45 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/19 13:49:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	get_state_nb_philo_fork(t_state *state, t_state_option option)
{
	if (option == FORK)
		return (state->nb_fork);
	else
		return (state->nb_philo);
}

int	get_state_time_to_die(t_state *state)
{
	return (state->time_to_die);
}

int	get_state_time_to_eat(t_state *state)
{
	return (state->time_to_eat);
}

int	get_state_time_to_sleep(t_state *state)
{
	return (state->time_to_sleep);
}

int	get_state_nb_time_to_eat(t_state *state)
{
	return (state->nb_time_to_eat);
}
