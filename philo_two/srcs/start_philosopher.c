/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosopher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:16:08 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/16 13:45:45 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static	void	dead_setter(t_philo *philo)
{
	t_time	*time;
	long	value;

	time = get_philo_time_addr(philo);
	value = (get_philo_time_to_die(philo) - get_time_second_tick(time));
	if (value <= 0)
	{
		set_philo_died(philo, true);
		return ;
	}
	else
		return ;
}

void			*check_status(void *param)
{
	t_philo	*philo;
	t_state	*state;

	philo = (t_philo*)param;
	state = get_philo_state_addr(philo);
	if (get_state_nb_time_to_eat(state) == 0)
		state->over = true;
	while (state->over == false)
	{
		if (state->over == true)
			return (NULL);
		if (get_state_nb_time_to_eat(state) == get_philo_nb_eat(philo))
			state->over = true;
		dead_setter(philo);
		if (get_philo_died(philo) == true)
		{
			philo_msg(philo, "died\n");
			state->over = true;
		}
		philo = get_philo_next_addr(philo);
	}
	return (param);
}

void			*routine(void *param)
{
	t_philo	*philo;
	t_state	*state;

	philo = (t_philo*)param;
	state = get_philo_state_addr(philo);
	while (state->over == false)
	{
		if (get_state_nb_philo_fork(state, PHILO) > 1)
		{
			if (state->over == true)
				return (NULL);
			if (state->over == false)
				philo_msg(philo, "is thinking\n");
			eating(philo);
			sleeping(philo);
		}
	}
	return (param);
}

void			start_philosopher(t_philo *philo, pthread_t *status)
{
	t_state		*state;
	t_time		*time;
	int			i;

	i = -1;
	time = get_philo_time_addr(philo);
	state = get_philo_state_addr(philo);
	set_time_first_tick(time);
	while (++i < get_state_nb_philo_fork(state, PHILO))
	{
		pthread_create(get_philo_thread(philo), NULL, routine, philo);
		pthread_detach(*(get_philo_thread(philo)));
		philo = get_philo_next_addr(philo);
	}
	pthread_create(status, NULL, check_status, philo);
	return ;
}
