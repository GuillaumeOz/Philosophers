/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:10:17 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/16 19:24:38 by gozsertt         ###   ########.fr       */
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
#include <inttypes.h>

#include "philo_one_time.h"
#include "philo_one_state.h"
#include "philo_one_philo.h"

// DEL THIS PART

# define PRINTS(x) printf("%s\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTD(x) printf("%d\n", x);
# define PRINTLD(x) printf("%ld\n", x);

// DEL THIS PART


typedef enum	e_error
{
	ERROR_TIME,
	ERROR_STATE,

	NONE,
}				t_error;

void			error_msg(char *msg);
int				quit_philo(int error_code, t_state *state);

size_t			ft_strlen(char *str);
int				ft_atoi_philo(char *str, t_state *state);
bool			ft_is_digit(char c);

#endif