/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_time_constructor_destructor.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:51:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/15 18:32:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_time	*malloc_time(void)
{
	t_time *time;

	time = (t_time*)malloc(sizeof(t_time));
	if (time == NULL)
	{
		error_msg("Error: malloc_time failed");
		time->error_time = true;
		return (NULL);
	}
	*time = create_time();
	return (time);
}

t_time	create_time(void)
{
	t_time	time;

	time.first_tick = 0;
	time.second_tick = 0;
	time.error_time = false;
	set_time_start_time(&time);
	return (time);
}

void	destroy_time(t_time time)
{
	memset(&time, 0, sizeof(t_time));
}

void	free_time(t_time *time)
{
	destroy_time(*time);
	free(time);
}
