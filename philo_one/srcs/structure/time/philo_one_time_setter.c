/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_time_setter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 12:40:19 by gozsertt          #+#    #+#             */
/*   Updated: 2020/09/25 14:27:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern t_time	*g_time;

void			set_time_start_time()
{
	struct	timeval	*get_time;
	int				state;

	state = gettimeofday(get_time, NULL);
	if (state == -1)
	{
		error_msg("Error: Time error\n");
		g_time->error_time = true;
	}
	g_time->start_time = (get_time->tv_sec * 1000) 
		+ (get_time->tv_usec * 1000);
}

void			set_time_first_tick()
{
	struct	timeval	*get_time;
	int				state;

	state = gettimeofday(get_time, NULL);
	if (state == -1)
	{
		error_msg("Error: Time error\n");
		g_time->error_time = true;
	}
	g_time->first_tick = (get_time->tv_sec * 1000) 
		+ (get_time->tv_usec * 1000);
}

void			set_time_second_tick()
{
	struct	timeval	*get_time;
	int				state;

	state = gettimeofday(get_time, NULL);
	if (state == -1)
	{
		error_msg("Error: Time error\n");
		g_time->error_time = true;
	}
	g_time->second_tick = (get_time->tv_sec * 1000)
		+ (get_time->tv_usec * 1000) - get_time_second_tick();
}
