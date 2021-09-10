/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_t_time.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:22:34 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/01 01:08:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_T_TIME_H
# define PHILO_T_TIME_H

typedef struct s_time
{
	unsigned long	start_time;
	unsigned long	first_tick;
	unsigned long	second_tick;
	bool			error_time;
}					t_time;

/*
**	t_time Constructor - Destructor
*/

t_time				*malloc_time(void);
t_time				create_time(void);
void				destroy_time(t_time time);
void				free_time(t_time *time);

/*
**	t_time Getter - Setter
*/

unsigned long		get_time_start_time(t_time *time);
unsigned long		get_time_first_tick(t_time *time);
unsigned long		get_time_second_tick(t_time *time);

void				set_time_start_time(t_time *time);
void				set_time_first_tick(t_time *time);
void				set_time_second_tick(t_time *time);

#endif
