/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_philo.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:21:21 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/19 20:01:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_PHILO_H
# define PHILO_ONE_PHILO_H

typedef struct	s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	fork;
	bool			died;
	bool			error_philo;
	t_time			*time;
	t_state			*state;
	struct	s_philo	*next;
	struct	s_philo *previous;
}				t_philo;

/*
**	t_time Constructor - Destructor
*/

t_philo			*malloc_philo(t_time *time, t_state *state);
void			create_philo(t_philo *philo, t_time *time,
					t_state *state, int id);
void			create_philo_link(t_philo *tmp, t_philo *philo);
void    		destroy_philo(t_philo state);
void    		free_philo(t_philo *state);

/*
**	t_state Getter - Setter
*/

int				get_philo_id(t_philo *philo);
pthread_t		get_philo_thread(t_philo *philo);
pthread_mutex_t	*get_philo_fork(t_philo *philo);
bool			get_philo_died(t_philo *philo);
bool			get_philo_error_philo(t_philo *philo);

t_time			*get_philo_time_addr(t_philo *philo);
t_state			*get_philo_state_addr(t_philo *philo);
t_philo			*get_philo_previous_addr(t_philo *philo);
t_philo			*get_philo_next_addr(t_philo *philo);

void			set_philo_id(t_philo *philo, int value);
void			set_philo_thread(t_philo *philo);
void			set_philo_fork(t_philo *philo);
void			set_philo_died(t_philo *philo);
void			set_philo_error_philo(t_philo *philo);

#endif