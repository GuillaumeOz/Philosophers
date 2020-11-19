/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:16:08 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/19 17:10:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void *thinking2(void *param)
{
	int i;

	i = 0;
	param = NULL;
	while (i < 10)
	{
		printf("\033[91mthread 2: %d\033[0m\n", i);
		i++;
	}
	return (param);
}

void *thinking1(void *param)
{
	int i;

	i = 0;
	param = NULL;
	while (i < 10)
	{
		printf("\033[95mthread 1: %d\033[0m\n", i);
		i++;
	}
	return (param);
}

	// pthread_t		*phil;
	// pthread_mutex_t	*mutex_fork;
	// pthread_mutex_t mutex_write;

void	*routine(void *param)
{
	// pthread_t	philo1;
	// pthread_t	philo2;

	// pthread_create(&philo1, NULL, &thinking1, NULL);
	// pthread_create(&philo2, NULL, &thinking1, NULL);

	t_philo *philo;

	philo = (t_philo*)param;
	PRINTS("COUCOU")
	PRINTD(philo->id)
	return(NULL);

	// pthread_join(philo1, NULL);
	// pthread_join(philo2, NULL);

// timestamp_in_ms X has taken a fork
// timestamp_in_ms X is eating
// timestamp_in_ms X is sleeping
// timestamp_in_ms X is thinking
// timestamp_in_ms X died
}
