/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_philo.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:21:21 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/16 19:39:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_PHILO_H
# define PHILO_ONE_PHILO_H

typedef struct	s_philo
{
	int				id;
	pthread_t		thread;
	bool			fork;

	bool			died;

	t_time			*time;
	t_state			*state;

	struct	s_philo	*next;
	struct	s_philo *previous;

	bool			error_philo;
}				t_philo;

/*
**	t_time Constructor - Destructor
*/

t_philo			*malloc_philo(int argc, char **argv);
t_philo			create_philo(int argc, char **argv);
void    		destroy_philo(t_philo state);
void    		free_philo(t_philo *state);

/*
**	t_state Getter - Setter
*/



#endif