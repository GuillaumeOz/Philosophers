/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_philo_address_getter.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:30:27 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/02 13:57:29 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

t_time			*get_philo_time_addr(t_philo *philo)
{
    return (philo->time);
}

t_state			*get_philo_state_addr(t_philo *philo)
{
    return (philo->state);
}

t_philo			*get_philo_previous_addr(t_philo *philo)
{
    return (philo->previous);
}

t_philo			*get_philo_next_addr(t_philo *philo)
{
    return (philo->next);
}

bool 			get_philo_error_philo(t_philo *philo)
{
	return (philo->error_philo);
}
