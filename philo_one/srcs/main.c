/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:09:40 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/10 16:57:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

// memset, malloc, free, write, usleep, gettimeofday,
// pthread_create, pthread_detach, pthread_join,
// pthread_mutex_init, pthread_mutex_destroy,
// pthread_mutex_lock, pthread_mutex_unlock

t_time *g_time = NULL;

int		quit_philo(int error_code, t_state *state)
{
	if (g_time != NULL)
		free_time(g_time);
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
	//pthread_t   thread0;
	t_state		*state;

	malloc_time();
	if (g_time->error_time == true)
		return (quit(ERROR_TIME, NULL));
	state = malloc_state(argc, argv);
	if (state->error_state == true)
		return (quit(ERROR_STATE, state));
	// routine();
	return (0);
}
