/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_time_constructor_destructor.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:51:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/09/25 16:38:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern t_time	*g_time;

void	malloc_time(void)
{
	g_time = (t_time*)malloc(sizeof(t_time));
	if (g_time == NULL)
	{
		error_msg("Error: malloc_time failed");
		g_time->error_time = true;
	}
	create_time();
}

void  create_time()
{
	g_time->first_tick = 0;
	g_time->second_tick = 0;
	g_time->error_time = false;
	set_time_start_time();
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
