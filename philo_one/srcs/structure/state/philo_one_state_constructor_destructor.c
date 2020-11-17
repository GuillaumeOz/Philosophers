/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_state_constructor_destructor.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:28:45 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/16 12:13:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_state	*malloc_state(int argc, char **argv)
{
	t_state *state;

	state = (t_state*)malloc(sizeof(t_state));
	if (state == NULL)
	{
		error_msg("Error: malloc_state failed");
		state->error_state = true;
		return (state);
	}
	*state = create_state(argc, argv);
	return (state);
}

t_state	create_state(int argc, char **argv)
{
	t_state state;

	memset(&state, 0, sizeof(t_state));
	if (argc == 5 || argc == 6)
	{
		parse_philo(argv[1], &state);
		parse_time_to_die(argv[2], &state);
		parse_time_to_eat(argv[3], &state);
		parse_time_to_sleep(argv[4], &state);
		if (argc == 6)
			parse_nb_time_to_eat(argv[5], &state);
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
	memset(&state, 0, sizeof(state));
}

void    free_state(t_state *state)
{
	destroy_state(*state);
	free(state);
}
