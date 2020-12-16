/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_state_semaphore_constructor.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:54:37 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/16 14:57:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static	void	create_write_semaphore(t_state *state)
{
	state->write_semaphore_one = sem_open("write_semaphore_one",
		O_CREAT, 0777, 1);
	if (state->write_semaphore_one == SEM_FAILED)
	{
		error_msg("Error: create_state_semaphore malloc semaphore_one failed");
		state->error_state = true;
		return ;
	}
	state->write_semaphore_two = sem_open("write_semaphore_two",
		O_CREAT, 0777, 1);
	if (state->write_semaphore_two == SEM_FAILED)
	{
		error_msg("Error: create_state_semaphore malloc semaphore_two failed");
		state->error_state = true;
		return ;
	}
}

static	void	create_eat_semaphore(t_state *state)
{
	state->fork_semaphore = sem_open("fork_semaphore", O_CREAT, 0777,
		get_state_nb_philo_fork(state, FORK));
	if (state->fork_semaphore == SEM_FAILED)
	{
		error_msg(
			"Error: create_state_semaphore malloc fork_semaphore failed");
		state->error_state = true;
		return ;
	}
	state->fork_semaphore_priority = sem_open("fork_semaphore_priority",
		O_CREAT, 0777, 1);
	if (state->fork_semaphore_priority == SEM_FAILED)
	{
		error_msg("Error: create_state_semaphore malloc fork_priority failed");
		state->error_state = true;
		return ;
	}
}

void			create_state_semaphore(t_state *state)
{
	destroy_state(*state);
	create_write_semaphore(state);
	create_eat_semaphore(state);
}
