/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:09:40 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/16 13:39:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		quit_philo(int code, t_time *time, t_state *state, t_philo *philo)
{
	if (philo != NULL)
		free_philo(philo);
	if (time != NULL)
		free_time(time);
	if (state != NULL)
		free_state(state);
	return (code);
}

void	error_msg(char *msg)
{
	size_t	len;

	len = ft_strlen(msg);
	write(1, msg, len);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	t_state		*state;
	t_time		*time;
	t_philo		*philo;
	pthread_t	status;

	time = malloc_time();
	if (time->error_time == true)
		return (quit_philo(ERROR_TIME, time, NULL, NULL));
	state = malloc_state(argc, argv);
	if (state->error_state == true)
		return (quit_philo(ERROR_STATE, time, state, NULL));
	philo = malloc_philo(time, state);
	if (philo->error_philo == true)
		return (quit_philo(ERROR_PHILO, time, state, philo));
	start_philosopher(philo, &status);
	pthread_join(status, NULL);
	quit_philo(EXIT_SUCCESS, time, state, philo);
	return (0);
}
