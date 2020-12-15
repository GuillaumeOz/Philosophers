/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_state_pid_constructor.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:10:57 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/11 14:42:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	create_state_pid(t_state *state)
{
	pid_t	*ret;

	ret = (pid_t*)malloc(sizeof(pid_t) * get_state_nb_philo_fork(state, PHILO));
	if (ret == NULL)
	{
		error_msg("Error: create_state_pid malloc pid failed");
		state->error_state = true;
		return ;
	}
	memset(ret, 0, sizeof(pid_t) * get_state_nb_philo_fork(state, PHILO));
	state->pid = ret;
}
