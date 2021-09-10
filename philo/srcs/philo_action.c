/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:36:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/07 07:29:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_msg(t_philo *philo, t_state *state, char *msg)
{
	char	buff[100];
	t_time	*time;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	memset(buff, 0, 100);
	time = get_philo_time_addr(philo);
	set_time_second_tick(time);
	ft_putnbr(get_time_second_tick(time), buff, &i);
	buff[++i] = ' ';
	ft_putnbr(get_philo_id(philo), buff, &i);
	buff[++i] = ' ';
	while (msg[++j] != '\0')
		buff[++i] = msg[j];
	pthread_mutex_lock(state->write_mutex_one);
	if (state->over == false)
	{
		if (ft_strcmp(msg, "died\n") == true)
			state->over = true;
		write(1, buff, ft_strlen(buff));
	}
	pthread_mutex_unlock(state->write_mutex_one);
}

void	sleeping(t_philo *philo, t_state *state)
{
	if (state->over == false)
	{
		philo_msg(philo, state, "is sleeping\n");
		usleep(1000 * get_state_time_to_sleep(state));
	}
}

static void	taking_forks(t_philo *philo, t_state *state)
{
	pthread_mutex_lock(get_philo_fork(philo, RIGHT_FORK));
	if (state->over == false)
		philo_msg(philo, state, "has taken a fork\n");
	if (get_state_nb_philo_fork(state, PHILO) == 2)
		pthread_mutex_lock(philo->fork_mutex);
	else
		pthread_mutex_lock(get_philo_fork(philo, LEFT_FORK));
	if (state->over == false)
		philo_msg(philo, state, "has taken a fork\n");
}

static void	leaving_forks(t_philo *philo, t_state *state)
{
	pthread_mutex_unlock(get_philo_fork(philo, RIGHT_FORK));
	if (get_state_nb_philo_fork(state, PHILO) == 2)
		pthread_mutex_unlock(philo->fork_mutex);
	else
		pthread_mutex_unlock(get_philo_fork(philo, LEFT_FORK));
}

void	eating(t_philo *philo, t_state *state)
{
	if (state->over == false)
	{
		taking_forks(philo, state);
		set_philo_time_to_die(philo, get_state_time_to_die(state));
		philo_msg(philo, state, "is eating\n");
		usleep(1000 * get_state_time_to_eat(state));
		if (get_state_nb_time_to_eat(state) != -1)
			set_philo_nb_eat(philo, 1);
		leaving_forks(philo, state);
	}
}
