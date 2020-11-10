/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_time.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:22:34 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/10 17:36:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_TIME_H
# define PHILO_ONE_TIME_H

typedef struct		s_time
{
	unsigned long	start_time;
	unsigned long	first_tick;
	unsigned long	second_tick;
	bool			error_time;
}					t_time;

/*
**	t_time Constructor - Destructor
*/

void	malloc_time(void);
void	create_time(void);
void    destroy_time(t_time time);
void    free_time(t_time *time);

/*
**	t_time Getter - Setter 
*/

t_time				get_time();
unsigned	long	get_time_start_time();
unsigned	long	get_time_first_tick();
unsigned	long	get_time_second_tick();

void				set_time_start_time();
void				set_time_first_tick();
void				set_time_second_tick();

#endif