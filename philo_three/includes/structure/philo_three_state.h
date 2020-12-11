/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_state.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:51:51 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/11 14:40:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_STATE_H
# define PHILO_THREE_STATE_H

/*
** - nb_philo && nb_fork : number of philosopher and forks.
** - time_to_die : if a philosopher doesn't eat in "time_to_die" ms 
** after begin to eat or starting prog, he die.
** - time_to_eat : The time taken by a philosopher to eat 
** (He keep two fork during this time).
** - time_to_sleep : The time taken by a philosopher to sleep
** - number_of_time_each_philosophers_must_eat : Optionnal, if all philosophers
** had eat number_of..._eat the simulation stop. if this option is not specify, the
** simulation end when a philosopher die.
*/

typedef	struct	s_state
{
	int			nb_philo;
	int			nb_fork;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_time_to_eat;
	sem_t		*fork_semaphore;
	sem_t		*fork_semaphore_priority;
	sem_t		*write_semaphore_one;
	sem_t		*write_semaphore_two;
	pid_t		*pid;
	bool		over;
	bool		error_state;
}				t_state;

typedef	enum	e_state_option
{
	FORK,
	PHILO
}				t_state_option;

/*
**	t_state Constructor - Destructor
*/

t_state			*malloc_state(int argc, char **argv);
t_state			create_state(int argc, char **argv);
void			create_state_semaphore(t_state *state);
void			create_state_pid(t_state *state);
void    		destroy_state(t_state state);
void    		free_state(t_state *state);

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

sem_t			*get_state_fork_semaphore(t_state *state);
sem_t			*get_state_fork_semaphore_priority(t_state *state);
sem_t			*get_state_write_semaphore_one(t_state *state);
sem_t			*get_state_write_semaphore_two(t_state *state);

pid_t			get_state_pid(t_state *state, int pos);

void			set_state_nb_philo_fork(t_state *state,
					int value, t_state_option option);
void			set_state_time_to_die(t_state *state, int value);
void			set_state_time_to_eat(t_state *state, int value);
void			set_state_time_to_sleep(t_state *state, int value);
void			set_state_nb_time_to_eat(t_state *state, int value);

void			set_state_pid(t_state *state, pid_t value, int pos);

#endif