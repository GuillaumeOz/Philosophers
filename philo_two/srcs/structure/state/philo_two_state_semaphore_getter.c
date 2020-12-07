/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_state_semaphore_getter.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:56:52 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/07 16:00:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

sem_t	*get_state_fork_semaphore(t_state *state)
{
	return (state->fork_semaphore);
}

sem_t	*get_state_fork_semaphore_priority(t_state *state)
{
	return (state->fork_semaphore_priority);
}

sem_t	*get_state_write_semaphore_one(t_state *state)
{
	return (state->write_semaphore_one);
}

sem_t	*get_state_write_semaphore_two(t_state *state)
{
	return (state->write_semaphore_two);
}
