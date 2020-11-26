/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:36:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/26 22:36:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern bool g_over;

void		philo_msg(t_philo *philo, char *msg)
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
	while(msg[++j] != '\0')
		buff[++i] = msg[j];
	pthread_mutex_lock(state->write_mutex);
	if (g_over == false)
		write(1, buff, ft_strlen(buff));
	pthread_mutex_unlock(state->write_mutex);
}

void			sleeping(t_philo *philo)
{
	t_state	*state;

	state = get_philo_state_addr(philo);
	philo_msg(philo ,"is sleeping\n");
	usleep(1000 * get_state_time_to_sleep(state));	
}

static	void	taking_forks(t_philo *philo)
{
	pthread_mutex_lock(get_philo_fork(philo, RIGHT_FORK));
	philo_msg(philo ,"has taken a fork\n");
	pthread_mutex_lock(get_philo_fork(philo, LEFT_FORK));
	philo_msg(philo ,"has taken a fork\n");
}

static	void	leaving_forks(t_philo *philo)
{
	pthread_mutex_unlock(get_philo_fork(philo, RIGHT_FORK));
	pthread_mutex_unlock(get_philo_fork(philo, LEFT_FORK));
}

void			eating(t_philo *philo)
{
	t_state	*state;

	state = get_philo_state_addr(philo);
	taking_forks(philo);
	philo_msg(philo ,"is eating\n");
	set_philo_time_to_die(philo, get_state_time_to_die(state));
	usleep(1000 * get_state_time_to_eat(state));
	set_philo_nb_eat(philo, 1);
	leaving_forks(philo);
}
