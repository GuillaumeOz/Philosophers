/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:10:17 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/09 19:49:29 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>

#include "philo_one_time.h"
#include "philo_one_state.h"

// DEL THIS PART

# define PRINTS(x) printf("%s\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTD(x) printf("%d\n", x);
# define PRINTLD(x) printf("%ld\n", x);

// DEL THIS PART

typedef struct	s_philo
{
	int		id; // Philo ID

	bool	fork; // Need this ?
	bool	eating;
	bool	sleeping;
	bool	thinking;
	bool	died;

	bool	error_philo;

// timestamp_in_ms X has taken a fork
// timestamp_in_ms X is eating
// timestamp_in_ms X is sleeping
// timestamp_in_ms X is thinking
// timestamp_in_ms X died
}				t_philo;

typedef enum	e_error
{
	ERROR_TIME,
	ERROR_STATE,

	NONE,
}				t_error;

size_t	ft_strlen(char *str);

void	error_msg(char *msg);
int		quit_philo(int error_code, t_state *state);

#endif