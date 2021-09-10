/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start_philosopher.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:16:08 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/07 06:46:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	dead_setter(t_philo *philo)
{
	t_time	*time;
	long	value;

	time = get_philo_time_addr(philo);
	set_time_second_tick(time);
	value = (get_philo_time_to_die(philo) - get_time_second_tick(time));
	if (value <= 0)
	{
		set_philo_died(philo, true);
		return ;
	}
	else
		return ;
}

static void	check_time_to_eat(t_state *state, t_philo *philo, int *time_to_eat)
{
	if (get_state_nb_time_to_eat(state) <= get_philo_nb_eat(philo))
		*(time_to_eat) += 1;
	else
		*(time_to_eat) = 0;
	if (*(time_to_eat) == get_state_nb_philo_fork(state, PHILO))
		state->over = true;
}

void	*check_status(void *param)
{
	t_philo	*philo;
	t_state	*state;
	int		time_to_eat;

	philo = (t_philo *)param;
	state = get_philo_state_addr(philo);
	if (get_state_nb_time_to_eat(state) == 0)
		state->over = true;
	time_to_eat = 0;
	while (state->over == false)
	{
		if (state->over == true)
			return (NULL);
		if (get_state_nb_time_to_eat(state) != -1)
			check_time_to_eat(state, philo, &time_to_eat);
		dead_setter(philo);
		if (get_philo_died(philo) == true)
			philo_msg(philo, state, "died\n");
		philo = get_philo_next_addr(philo);
	}
	return (param);
}

void	*routine(void *param)
{
	t_philo	*philo;
	t_state	*state;

	philo = (t_philo *)param;
	state = get_philo_state_addr(philo);
	while (state->over == false)
	{
		if (get_state_nb_philo_fork(state, PHILO) > 1)
		{
			if (state->over == true)
				return (NULL);
			if (state->over == false)
				philo_msg(philo, state, "is thinking\n");
			eating(philo, state);
			sleeping(philo, state);
		}
	}
	return (param);
}

void	start_philosopher(t_philo *philo, pthread_t *status)
{
	t_state	*state;
	t_time	*time;
	int		i;

	i = -1;
	time = get_philo_time_addr(philo);
	state = get_philo_state_addr(philo);
	set_time_first_tick(time);
	pthread_create(status, NULL, check_status, philo);
	while (++i < get_state_nb_philo_fork(state, PHILO))
	{
		pthread_create(get_philo_thread(philo), NULL, routine, philo);
		pthread_detach(*(get_philo_thread(philo)));
		philo = get_philo_next_addr(philo);
	}
	return ;
}
