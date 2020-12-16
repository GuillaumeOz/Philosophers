/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:36:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/16 13:47:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			philo_msg(t_philo *philo, char *msg)
{
	char	buff[100];
	t_time	*time;
	t_state	*state;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	memset(buff, 0, 100);
	state = get_philo_state_addr(philo);
	time = get_philo_time_addr(philo);
	set_time_second_tick(time);
	ft_putnbr(get_time_second_tick(time), buff, &i);
	buff[++i] = ' ';
	ft_putnbr(get_philo_id(philo), buff, &i);
	buff[++i] = ' ';
	while (msg[++j] != '\0')
		buff[++i] = msg[j];
	sem_wait(get_state_write_semaphore_one(state));
	usleep(1000);
	sem_wait(get_state_write_semaphore_two(state));
	write(1, buff, ft_strlen(buff));
	sem_post(get_state_write_semaphore_two(state));
	sem_post(get_state_write_semaphore_one(state));
}

void			sleeping(t_philo *philo)
{
	t_state	*state;

	state = get_philo_state_addr(philo);
	if (state->over == false)
	{
		philo_msg(philo, "is sleeping\n");
		usleep(1000 * get_state_time_to_sleep(state));
	}
}

static void		taking_forks(t_philo *philo)
{
	t_state	*state;

	state = get_philo_state_addr(philo);
	sem_wait(get_state_fork_semaphore(state));
	if (state->over == false)
		philo_msg(philo, "has taken a fork\n");
	sem_wait(get_state_fork_semaphore(state));
	if (state->over == false)
		philo_msg(philo, "has taken a fork\n");
}

static void		leaving_forks(t_philo *philo)
{
	t_state	*state;

	state = get_philo_state_addr(philo);
	sem_post(get_state_fork_semaphore(state));
	sem_post(get_state_fork_semaphore(state));
}

void			eating(t_philo *philo)
{
	t_state	*state;

	state = get_philo_state_addr(philo);
	if (state->over == false)
	{
		if (get_state_nb_philo_fork(state, FORK) == 2)
			sem_wait(get_state_fork_semaphore_priority(state));
		taking_forks(philo);
		philo_msg(philo, "is eating\n");
		set_philo_time_to_die(philo, get_state_time_to_die(state));
		usleep(1000 * get_state_time_to_eat(state));
		if (get_state_nb_time_to_eat(state) != -1)
			set_philo_nb_eat(philo, 1);
		leaving_forks(philo);
		if (get_state_nb_philo_fork(state, FORK) == 2)
			sem_post(get_state_fork_semaphore_priority(state));
	}
}
