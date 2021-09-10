/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_t_state_pid_constructor.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:10:57 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/01 01:58:01 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_state_pid(t_state *state)
{
	pid_t	*ret;

	ret = (pid_t *)malloc(sizeof(pid_t)
			* get_state_nb_philo_fork(state, PHILO));
	if (ret == NULL)
	{
		error_msg("Error: create_state_pid malloc pid failed");
		state->error_state = true;
		return ;
	}
	memset(ret, 0, sizeof(pid_t) * get_state_nb_philo_fork(state, PHILO));
	state->pid = ret;
}
