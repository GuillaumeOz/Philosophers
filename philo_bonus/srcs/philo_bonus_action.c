/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:36:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/08 18:03:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	sem_wait(get_state_write_semaphore_one(state));
	write(1, buff, ft_strlen(buff));
	if (ft_strcmp(msg, "died\n") == false)
		sem_post(get_state_write_semaphore_one(state));
}

void	sleeping(t_philo *philo, t_state *state)
{
	if (state->over == false)
	{
		philo_msg(philo, state, "is sleeping\n");
		if (state->over == false)
			usleep(1000 * get_state_time_to_sleep(state));
	}
}

static void	taking_forks(t_philo *philo, t_state *state)
{
	sem_wait(get_state_fork_semaphore(state));
	if (state->over == false)
		philo_msg(philo, state, "has taken a fork\n");
	sem_wait(get_state_fork_semaphore(state));
	if (state->over == false)
		philo_msg(philo, state, "has taken a fork\n");
}

static void	leaving_forks(t_state *state)
{
	sem_post(get_state_fork_semaphore(state));
	sem_post(get_state_fork_semaphore(state));
}

void	eating(t_philo *philo, t_state *state)
{
	if (state->over == false)
	{
		if (get_state_nb_philo_fork(state, FORK) == 2)
			sem_wait(get_state_fork_semaphore_priority(state));
		taking_forks(philo, state);
		set_philo_time_to_die(philo, get_state_time_to_die(state));
		philo_msg(philo, state, "is eating\n");
		usleep(1000 * get_state_time_to_eat(state));
		if (get_state_nb_time_to_eat(state) != -1)
			set_philo_nb_eat(philo, 1);
		leaving_forks(state);
		if (get_state_nb_philo_fork(state, FORK) == 2)
			sem_post(get_state_fork_semaphore_priority(state));
	}
}
