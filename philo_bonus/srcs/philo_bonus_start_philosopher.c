/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_start_philosopher.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:16:08 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/08 18:25:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	dead_setter(t_philo *philo, t_time *time)
{
	long	value;

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
	if (state->over == true)
		sem_post(get_state_write_semaphore_two(state));
}

void	*check_status(void *param)
{
	t_philo	*philo;
	t_state	*state;
	t_time	*time;
	int		time_to_eat;

	philo = (t_philo *)param;
	state = get_philo_state_addr(philo);
	time = get_philo_time_addr(philo);
	if (get_state_nb_time_to_eat(state) == 0)
		return (NULL);
	time_to_eat = 0;
	while (state->over == false)
	{
		if (state->over == true)
			return (NULL);
		if (get_state_nb_time_to_eat(state) != -1)
			check_time_to_eat(state, philo, &time_to_eat);
		dead_setter(philo, time);
		if (get_philo_died(philo) == true)
		{
			philo_msg(philo, state, "died\n");
			sem_post(get_state_write_semaphore_three(state));
		}
	}
	return (param);
}

void	routine(t_philo *philo, t_state *state, pthread_t *status)
{
	t_time		*time;

	time = get_philo_time_addr(philo);
	pthread_create(status, NULL, check_status, philo);
	pthread_detach(*status);
	while (1)
	{
		if (get_state_nb_philo_fork(state, PHILO) > 1)
		{
			if (state->over == false)
				philo_msg(philo, state, "is thinking\n");
			eating(philo, state);
			sleeping(philo, state);
		}
	}
}

void	start_philosopher(t_philo *philo, pthread_t *status)
{
	t_state		*state;
	t_time		*time;
	pid_t		ret;
	int			i;

	i = -1;
	time = get_philo_time_addr(philo);
	state = get_philo_state_addr(philo);
	set_time_first_tick(time);
	while (++i < get_state_nb_philo_fork(state, PHILO))
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
