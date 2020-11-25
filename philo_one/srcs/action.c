/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:36:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/25 16:16:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			sleeping(t_philo *philo)
{
	t_state	*state;

	state = get_philo_state_addr(philo);
	ft_philo_msg(philo ,"is sleeping\n");
	usleep(1000 * get_state_time_to_sleep(state));
}

static	void	taking_forks(t_philo *philo)
{
	pthread_mutex_lock(get_philo_fork(philo, RIGHT_FORK));
	ft_philo_msg(philo ,"has taken a fork\n");
	pthread_mutex_lock(get_philo_fork(philo, LEFT_FORK));
	ft_philo_msg(philo ,"has taken a fork\n");
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
	ft_philo_msg(philo ,"is eating\n");
	usleep(1000 * get_state_time_to_eat(state));
	set_philo_nb_eat(philo, 1);
	leaving_forks(philo);
}
