/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_philo_setter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:39:07 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/25 16:24:40 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			set_philo_id(t_philo *philo, int value)
{
	philo->id = value;
}

void			set_philo_thread(t_philo *philo)
{
	philo->thread = (pthread_t*)malloc(sizeof(pthread_t));
	if (philo->thread == NULL)
	{
		error_msg("Error: set_philo_thread malloc thread failed");
		philo->error_philo = true;
		return ;
	}
}

void			set_philo_fork_mutex(t_philo *philo)
{
	philo->fork_mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
	if (philo->fork_mutex == NULL)
	{
		error_msg("Error: set_philo_thread malloc thread failed");
		philo->error_philo = true;
		return ;
	}
	pthread_mutex_init(philo->fork_mutex, NULL);
}

void			set_philo_died(t_philo *philo, bool value)
{
	philo->died = value;
}

void			set_philo_nb_eat(t_philo *philo, int value)
{
	philo->nb_eat += value;
}
