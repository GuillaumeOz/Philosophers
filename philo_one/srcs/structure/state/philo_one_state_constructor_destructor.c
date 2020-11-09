/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_state_constructor_destructor.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:28:45 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/09 19:54:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_state	*malloc_state(int argc, char **argv)
{
	t_state *state;

	state = (t_state*)malloc(sizeof(state));
	if (state == NULL)
	{
		error_msg("Error: malloc_state failed");
		state->error_state = true;
		return ;
	}
	*state = create_state(argc, argv);
	return (state);
}

// typedef	struct s_state
// {
// 	int		nb_philo;
// 	int		nb_fork;
// 	int		time_to_die;
// 	int		time_to_eat;
// 	int		time_to_sleep;
// 	int		nb_time_to_eat;
// 	bool	error_state;
// }				t_state;

t_state	create_state(int argc, char **argv)
{
	t_state state;

	memset(&state, 0, sizeof(t_state));
	if (argc == 5 || argc == 6)
	{
		parse_philo(argv[1]);
		parse_time_to_die(argv[2]);
		parse_time_to_eat(argv[3]);
		parse_time_to_sleep(argv[4]);
		if (argc == 6)
			parse_nb_time_to_eat(argv[5]);
	}
	else
	{
		error_msg("Error: Arguments\n");
		state.error_state = true;
	}
	return(state);
}

void    destroy_state(t_state state)
{

}

void    free_state(t_state *state)
{
	destroy_state(*state);
	free(state);
}