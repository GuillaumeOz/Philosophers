/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_t_philo_constructor_destructor.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:38:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/07 02:45:01 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*malloc_philo(t_time *time, t_state *state)
{
	t_philo	*philo;
	t_philo	*first;
	t_philo	*tmp;
	int		i;

	i = -1;
	tmp = NULL;
	while (++i < state->nb_philo)
	{
		philo = (t_philo *)malloc(sizeof(t_philo));
		if (philo == NULL)
		{
			error_msg("Error: malloc_philo failed");
			philo->error_philo = true;
			return (NULL);
		}
		if (i == 0)
			first = philo;
		create_philo(philo, time, state, i + 1);
		create_philo_link(&tmp, philo);
	}
	first->previous = philo;
	philo->next = first;
	return (first);
}

void	create_philo_link(t_philo **tmp, t_philo *philo)
{
	if (*tmp == NULL)
	{
		*tmp = philo;
		return ;
	}
	(*tmp)->next = philo;
	philo->previous = *tmp;
	*tmp = philo;
}

void	create_philo(t_philo *philo, t_time *time, t_state *state, int id)
{
	philo->id = id;
	set_philo_died(philo, false);
	set_philo_nb_eat(philo, 0);
	philo->nb_eat = 0;
	philo->time_die = get_state_time_to_die(state);
	philo->error_philo = false;
	philo->time = time;
	philo->state = state;
}

void	destroy_philo(t_philo philo)
{
	memset(&philo, 0, sizeof(t_philo));
}

void	free_philo(t_philo *philo)
{
	t_state	*state;
	t_philo	*tmp;
	int		i;

	i = -1;
	state = get_philo_state_addr(philo);
	while (++i < get_state_nb_philo_fork(state, PHILO))
	{
		tmp = get_philo_next_addr(philo);
		destroy_philo(*philo);
		free(philo);
		philo = tmp;
	}
}
