/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:09:40 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/16 19:45:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

// memset, malloc, free, write, usleep, gettimeofday,

// pthread_create, pthread_detach, pthread_join,

// pthread_mutex_init, pthread_mutex_destroy,
// pthread_mutex_lock, pthread_mutex_unlock

int		quit_philo(int error_code, t_time *time, t_state *state)
{
	if (time != NULL)
		free_time(time);
	if (state != NULL)
		free_state(state);
	return (error_code);
}

void	error_msg(char *msg)
{
	size_t	len;

	len = ft_strlen(msg);
	write(1, msg, len);
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	t_state		*state;
	t_time		*time;

	time = malloc_time();
	if (time->error_time == true)
		return (quit_philo(ERROR_TIME, time, NULL));
	state = malloc_state(argc, argv);
	if (state->error_state == true)
		return (quit_philo(ERROR_STATE, time, state));
	// malloc_philo(g_time, state);
	routine();

	quit_philo(ERROR_STATE, time, state);
	return (0);
}


	// PRINTS("TIME STRUCTURE\n")
	// PRINTS("\nStart_time\n")
	// PRINTLD(get_time_start_time(state, PHILO))

	// PRINTS("\nFirst_tick\n")
	// PRINTLD(get_time_first_tick(state, FORK))
	// PRINTS("\nSecond_tick\n")
	// PRINTLD(get_time_second_tick(state))

	// PRINTS("STATE STRUCTURE\n")
	// PRINTS("\nnb_philo\n")
	// PRINTD(get_state_nb_philo_fork(state, PHILO))
	// PRINTS("\nnb_fork\n")
	// PRINTD(get_state_nb_philo_fork(state, FORK))
	// PRINTS("\ntime_to_die\n")
	// PRINTD(get_state_time_to_die(state))
	// PRINTS("\ntime_to_eat\n")
	// PRINTD(get_state_time_to_eat(state))
	// PRINTS("\ntime_to_sleep\n")
	// PRINTD(get_state_time_to_sleep(state))
	// PRINTS("\nnb_time_to_eat\n")
	// PRINTD(get_state_nb_time_to_eat(state))