/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosopher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:16:08 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/24 19:56:08 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern bool g_over;

void	*check_status(void *param)
{
	t_philo	*philo;
	t_state	*state;

	philo = (t_philo*)param;
	state = get_philo_state_addr(philo);
	if (get_state_nb_time_to_eat(state) == 0)
		g_over = true;
	while (1)
	{
		if (get_state_nb_time_to_eat(state) == get_philo_nb_eat(philo))
			g_over = true;
		if (get_philo_died(philo) == true)
		{
			ft_philo_msg(philo, " died");
			g_over = true;
		}
		philo = get_philo_next_addr(philo);
	}
	return (param);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo*)param;
	while(1)
	{
		if (g_over == true)
			return (NULL);
		PRINTD(get_philo_id(philo))
		// // timestamp_in_ms X is thinking
		// // timestamp_in_ms X has taken a fork
		// // timestamp_in_ms X is eating
		// // timestamp_in_ms X is sleeping
		// // timestamp_in_ms X died
	}
	return(param);
}

void	start_philosopher(t_philo *philo)
{
	pthread_t	status;
	t_state		*state;
	int			i;

	pthread_create(&status, NULL, check_status, philo);
	pthread_detach(status);
	state = get_philo_state_addr(philo);
	i = -1;
	while(++i < get_state_nb_philo_fork(state, PHILO))
	{
		pthread_create(get_philo_thread(philo), NULL, routine, philo);
		philo = get_philo_previous_addr(philo);
	}
	return ;
}
