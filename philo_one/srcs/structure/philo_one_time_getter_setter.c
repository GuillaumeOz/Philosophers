/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_time_getter_setter.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:56:52 by gozsertt          #+#    #+#             */
/*   Updated: 2020/09/24 18:51:27 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

const t_time	get_time()
{
	return (*g_time);
}

const	long	get_time_start_time()
{
	return (g_time->start_time);
}

const	long	get_time_first_tick()
{
	return (g_time->first_tick);
}

const	long	get_time_second_tick()
{
	return (g_time->second_tick);
}

void			set_time(t_time *time)
{
	struct	timeval	*get_time;
	int				state;

	state = gettimeofday(&time, NULL);
	if (state == -1)
		error_msg("Error: Time error\n");
	PRINTLD(time.tv_usec  + (time.tv_sec)/1000000) // x 1000
	PRINTLD(time.tv_sec * 1000) // x 1000
	PRINTLD(time.tv_usec / 1000) // x 1000

}
