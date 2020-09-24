/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_time_constructor_destructor.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:51:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/09/24 18:43:01 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_time  *malloc_time(void)
{
	t_time  *time;

	time = (t_time*)malloc(sizeof(t_time));
	if (time == NULL)
		error_msg("Error: malloc_time failed");
	*time = create_time(0, 0);
}

t_time  create_time(unsigned long first_tick, unsigned long second_tick)
{
	struct	timeval	*get_time;
	t_time			time;
	int				state;

	state = gettimeofday(&time, NULL);
	if (state == -1)
		error_msg("Error: create_time error\n");
	time.start_time = (get_time->tv_sec * 1000) + (get_time->tv_usec * 1000);
	time.first_tick = 0;
	time.second_tick = 0;
	return (time);
}

void    destroy_time(t_time time)
{
	memset(&time, 0, sizeof(t_time));
}

void    free_time(t_time *time)
{
	destroy_time(*time);
	free(time);
}
