/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_time_getter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:56:52 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/26 15:26:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

unsigned	long	get_time_start_time(t_time *time)
{
	return (time->start_time);
}

unsigned	long	get_time_first_tick(t_time *time)
{
	return (time->first_tick);
}

unsigned	long	get_time_second_tick(t_time *time)
{
	return (time->second_tick);
}

int					get_philo_time_to_die(t_philo *philo)
{
	return (philo->time_die);
}
