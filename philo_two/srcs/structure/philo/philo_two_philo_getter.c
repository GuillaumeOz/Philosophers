/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_philo_getter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:39:01 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/02 13:58:14 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int				get_philo_id(t_philo *philo)
{
	return (philo->id);
}

pthread_t		*get_philo_thread(t_philo *philo)
{
	return (philo->thread);
}

pthread_mutex_t	*get_philo_fork(t_philo *philo, t_fork_choice fork_choice)
{
	t_philo	*philo_right;
	t_philo	*philo_left;

	philo_right = get_philo_previous_addr(philo);
	philo_left = get_philo_next_addr(philo);
	if (fork_choice == RIGHT_FORK)
		return (philo_right->fork_mutex);
	else
		return (philo_left->fork_mutex);
}

bool 			get_philo_died(t_philo *philo)
{
	return (philo->died);
}

int 			get_philo_nb_eat(t_philo *philo)
{
	return (philo->nb_eat);
}
