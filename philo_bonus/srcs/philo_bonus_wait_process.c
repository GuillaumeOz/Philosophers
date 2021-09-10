/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_wait_process.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:16:59 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/08 18:34:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*collect_end_eating_process(void *param)
{
	t_state	*state;
	int		i;

	i = 0;
	state = (t_state *)param;
	while (i < get_state_nb_philo_fork(state, PHILO))
	{
		sem_wait(get_state_write_semaphore_two(state));
		i++;
	}
	sem_post(get_state_write_semaphore_three(state));
	return (param);
}

void	wait_process(t_state *state)
{
	pthread_t	status;

	if (get_state_nb_time_to_eat(state) != -1)
	{
		pthread_create(&status, NULL, collect_end_eating_process, state);
		pthread_detach(status);
	}
	sem_wait(get_state_write_semaphore_three(state));
}
