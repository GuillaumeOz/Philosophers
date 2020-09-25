/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_time_getter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:56:52 by gozsertt          #+#    #+#             */
/*   Updated: 2020/09/25 14:12:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern t_time *g_time;

t_time	get_time()
{
	return (*g_time);
}

unsigned	long	get_time_start_time()
{
	return (g_time->start_time);
}

unsigned	long	get_time_first_tick()
{
	return (g_time->first_tick);
}

unsigned	long	get_time_second_tick()
{
	return (g_time->second_tick);
}
