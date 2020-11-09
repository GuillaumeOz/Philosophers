/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_state.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:51:51 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/09 19:48:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_STATE_H
# define PHILO_ONE_STATE_H

typedef	struct s_state
{
	int		nb_philo;
	int		nb_fork;
	// >> number_of_philosopher << --> number of philosopher and forks.
	int		time_to_die;
	// >> time_to_die << --> if a philosopher doesn't eat in "time_to_die" ms 
	// after begin to eat or starting prog, he die.
	int		time_to_eat;
	// >> time_to_eat << --> The time taken by a philosopher to eat 
	//(He keep two fork during this time)
	int		time_to_sleep;
	// >> time_to_sleep << --> The time taken by a philosopher to sleep
	int		nb_time_to_eat;
	// >> number_of_time_each_philosophers_must_eat << --> Optionnal, if all philosophers
	// had eat number_of..._eat the simulation stop. if this option is not specify, the
	//simulation end when a philosopher die.
	bool	error_state;
}				t_state;

t_state	*malloc_state(int argc, char **argv);
t_state	create_state(int argc, char **argv);
void    destroy_state(t_state state);
void    free_state(t_state *state);

void	parse_philo(char *arg);
void	parse_time_to_die(char *arg);
void	parse_time_to_eat(char *arg);
void	parse_time_to_sleep(char *arg);
void	parse_nb_time_to_eat(char *arg);

#endif