/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_time_setter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 12:40:19 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/16 15:10:01 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			set_time_start_time(t_time *time)
{
	struct timeval	get_time;
	int				state;

	state = gettimeofday(&get_time, NULL);
	if (state == -1)
	{
		error_msg("Error: Time error\n");
		time->error_time = true;
	}
	time->start_time = (get_time.tv_sec * 1000)
		+ (get_time.tv_usec / 1000);
}

void			set_time_first_tick(t_time *time)
{
	struct timeval	get_time;
	int				state;

	state = gettimeofday(&get_time, NULL);
	if (state == -1)
	{
		error_msg("Error: Time error\n");
		time->error_time = true;
	}
	time->first_tick = (get_time.tv_sec * 1000)
		+ (get_time.tv_usec / 1000);
}

void			set_time_second_tick(t_time *time)
{
	struct timeval	get_time;
	int				state;

	state = gettimeofday(&get_time, NULL);
	if (state == -1)
	{
		error_msg("Error: Time error\n");
		time->error_time = true;
	}
	time->second_tick = (get_time.tv_sec * 1000)
		+ (get_time.tv_usec / 1000) - get_time_first_tick(time);
}
