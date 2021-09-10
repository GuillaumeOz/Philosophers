/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:09:40 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/08 18:29:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	quit_philo(int code, t_time *time, t_state *state, t_philo *philo)
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

void	kill_process(t_state *state)
{
	int		i;

	i = 0;
	while (i < get_state_nb_philo_fork(state, PHILO))
	{
		kill(get_state_pid(state, i), SIGKILL);
		i++;
	}
}

int	main(int argc, char **argv)
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
	if (get_state_nb_time_to_eat(state) == 0)
	{
		quit_philo(EXIT_SUCCESS, time, state, philo);
		return (0);
	}
	start_philosopher(philo, &status);
	wait_process(state);
	kill_process(state);
	quit_philo(EXIT_SUCCESS, time, state, philo);
	return (0);
}
