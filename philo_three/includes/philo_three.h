/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:10:17 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/07 18:51:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

# include <fcntl.h> /* Pour les constantes O_* */
# include <sys/stat.h> /* Pour les constantes « mode » */
// SEM_FAILED ((sem_t *) 0)

#include "philo_three_time.h"
#include "philo_three_state.h"
#include "philo_three_philo.h"

// DEL THIS PART

# define DEBUG write(1, "ICI\n", 4);
# define PRINTS(x) printf("%s\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTD(x) printf("%d\n", x);
# define PRINTP(x) printf("%p\n", x);
# define PRINTLD(x) printf("%ld\n", x);

// DEL THIS PART

/*
** Constructor error handling
*/

typedef enum	e_error
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
void			philo_msg(t_philo *philo, char *msg);

void			sleeping(t_philo *philo);
void			eating(t_philo *philo);
void			*check_status(void *param);
void			*routine(void *param);
void			start_philosopher(t_philo *philo, pthread_t	*status);

#endif