/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_time.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:22:34 by gozsertt          #+#    #+#             */
/*   Updated: 2020/09/24 18:47:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_TIME_H
# define PHILO_ONE_TIME_H

typedef struct		s_time
{
	unsigned long	start_time;
	unsigned long	first_tick;
	unsigned long	second_tick;
}					t_time;

/*
**	t_time Constructor - Destructor
*/

t_time  *malloc_time(void);
t_time  create_time(unsigned long first_tick, unsigned long second_tick);
void    destroy_time(t_time time);
void    free_time(t_time *time);

/*
**	t_time Getter - Setter 
*/

// chaque element de la struct
// return(const t_time start_time);
const t_time	get_time(); 

// set la structure et/ou les 
// variables de cette structure
void	set_time(t_time *time);

/*
**	t_time Global
*/

t_time *g_time;

#endif