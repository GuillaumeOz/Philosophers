/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:10:17 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/06 19:54:04 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdio.h>
# include <string.h>
# include <inttypes.h>

# include "philo_t_time.h"
# include "philo_t_state.h"
# include "philo_t_philo.h"

/*
** Constructor error handling
*/

typedef enum e_error
{
	ERROR_TIME,
	ERROR_STATE,
	ERROR_PHILO,
	NONE,
}				t_error;

void			error_msg(char *msg);
int				quit_philo(int code, t_time *time, t_state *state,
					t_philo *philo);

size_t			ft_strlen(char *str);
int				ft_atoi_philo(char *str, t_state *state);
bool			ft_is_digit(char c);
void			ft_putnbr(unsigned long nb, char *buff, size_t *i);
bool			ft_strcmp(char *s1, char *s2);

void			philo_msg(t_philo *philo, t_state *state, char *msg);

void			sleeping(t_philo *philo, t_state *state);
void			eating(t_philo *philo, t_state *state);
void			*check_status(void *param);
void			*routine(void *param);
void			start_philosopher(t_philo *philo, pthread_t	*status);

#endif
