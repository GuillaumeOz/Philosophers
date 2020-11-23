/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_philo_getter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:39:01 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/23 12:23:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int				get_philo_id(t_philo *philo)
{
	return (philo->id);
}

pthread_t		*get_philo_thread(t_philo *philo)
{
	return (philo->thread);
}

pthread_mutex_t	*get_philo_fork(t_philo *philo)
{
	return (philo->fork_mutex);
}

bool 			get_philo_died(t_philo *philo)
{
	return (philo->died);
}

int 			get_philo_nb_eat(t_philo *philo)
{
	return (philo->nb_eat);
}
