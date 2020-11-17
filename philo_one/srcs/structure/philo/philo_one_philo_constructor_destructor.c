/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_philo_constructor_destructor.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:38:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/17 21:42:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philo	*malloc_philo(t_time *time, t_state *state)
{
	t_philo	*philo;
	t_philo	*first;
	t_philo *tmp;
	int		i;

	i = -1;
	tmp = NULL;
	while(++i < get_state_nb_philo_fork(state, PHILO))
	{
		philo = (t_philo*)malloc(sizeof(t_philo));
		if (philo == NULL)
		{
			error_msg("Error: malloc_philo failed");
			philo->error_philo = true;
			return ;
		}
		if (i = 0)
			first = philo;
		*philo = create_philo(time, state, i + 1);
		create_philo_link(tmp, philo);
	}
	first->previous = philo;
	philo->next = first;
	return (first);
}

void	create_philo_link(t_philo *tmp, t_philo *philo)
{
	if (tmp == NULL)
	{
		tmp = philo;
		return ;
	}
	tmp->next = philo;
	philo->previous = tmp;
	tmp = philo;
}

typedef struct	s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*fork;
	bool			died;
	bool			error_philo;
	t_time			*time;
	t_state			*state;
	struct	s_philo	*next;
	struct	s_philo *previous;
}				t_philo;

t_philo	create_philo(t_time *time, t_state *state, int id)
{
	t_philo philo;

	set_philo_id(&philo, id);
	set_philo_thread(&philo);


	set_philo_fork(t_philo *philo);
	set_philo_died(t_philo *philo);
	set_philo_error_philo(t_philo *philo);


	philo.died = false;
	philo.error_philo = false;
	philo.time = time;
	philo.state = state;
}

void	destroy_philo(t_philo philo)
{
	pthread_mutex_destroy(&(philo.fork));
	
}

void	free_philo(t_philo *philo)
{
	t_state	*state;
	int		i;

	i = -1;
	state = get_philo_state_addr(philo);
	while(++i < get_state_nb_philo_fork(state, PHILO))
	{
		destroy_philo(*philo);
		free(philo);
		philo = get_philo_next_addr(philo);
	}
}
