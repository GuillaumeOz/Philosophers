/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosopher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:16:08 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/14 19:20:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
		return (NULL);
	while (state->over == false)
	{
		if (state->over == true)
			return (NULL);
		if (get_state_nb_time_to_eat(state) == get_philo_nb_eat(philo))
			state->over = true;// OK
		dead_setter(philo);
		if (get_philo_died(philo) == true)
		{
			philo_msg(philo, "died\n");
			sem_wait(get_state_write_semaphore_two(state));
			state->over = true;// OK
			kill(0, SIGINT);
			exit(0);
		}
	}
	return (param);
}

void			routine(t_philo *philo, t_state *state, pthread_t *status)
{
	t_time		*time;

	time = get_philo_time_addr(philo);
	set_time_first_tick(time);
	pthread_create(status, NULL, check_status, philo);
	pthread_detach(*status);
	while(1)
	{
		if (get_state_nb_philo_fork(state, PHILO) > 1)
		{
			philo_msg(philo, "is thinking\n");
			eating(philo);
			sleeping(philo);
		}
	}
}

void			start_philosopher(t_philo *philo, pthread_t	*status)
{
	t_state		*state;
	pid_t		ret;
	int			i;

	i = -1;
	state = get_philo_state_addr(philo);
	while(++i < get_state_nb_philo_fork(state, PHILO))
	{
		ret = fork();
		if (ret < 0)
			exit(-1);
		if (ret != 0)
			set_state_pid(state, ret, i);
		if (ret == 0)
		{
			routine(philo, state, status);
			exit(0);
		}
		philo = get_philo_next_addr(philo);
	}
	return ;
}
