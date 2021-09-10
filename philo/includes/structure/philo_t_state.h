/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_t_state.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:51:51 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/06 23:06:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_T_STATE_H
# define PHILO_T_STATE_H

typedef struct s_state
{
	int				nb_philo;
	int				nb_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_to_eat;
	pthread_mutex_t	*write_mutex_one;
	bool			over;
	bool			error_state;
}				t_state;

typedef enum e_state_option
{
	FORK,
	PHILO
}				t_state_option;

/*
**	t_state Constructor - Destructor
*/

t_state			*malloc_state(int argc, char **argv);
t_state			create_state(int argc, char **argv);
void			create_state_write_mutex(t_state *state);
void			destroy_state(t_state state);
void			free_state(t_state *state);

/*
**	t_state Parser
*/

void			parse_philo(char *arg, t_state *state);
void			parse_time_to_die(char *arg, t_state *state);
void			parse_time_to_eat(char *arg, t_state *state);
void			parse_time_to_sleep(char *arg, t_state *state);
void			parse_nb_time_to_eat(char *arg, t_state *state);

/*
**	t_state Getter - Setter
*/

int				get_state_nb_philo_fork(t_state *state, t_state_option option);
int				get_state_time_to_die(t_state *state);
int				get_state_time_to_eat(t_state *state);
int				get_state_time_to_sleep(t_state *state);
int				get_state_nb_time_to_eat(t_state *state);

void			set_state_nb_philo_fork(t_state *state,
					int value, t_state_option option);
void			set_state_time_to_die(t_state *state, int value);
void			set_state_time_to_eat(t_state *state, int value);
void			set_state_time_to_sleep(t_state *state, int value);
void			set_state_nb_time_to_eat(t_state *state, int value);

#endif
