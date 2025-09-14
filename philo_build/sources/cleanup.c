/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:01:08 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/14 02:16:29 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_simulation(t_sim_data *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_of_philos)
	{
		if (&sim->philos[i])
			pthread_mutex_destroy(&sim->philos[i].personal_mutex);
		if (sim->philos[i].thread)
			pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < sim->num_of_philos)
	{
		if (&sim->forks[i])
			pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&sim->print_mutex);
	pthread_mutex_destroy(&sim->stop_mutex);
	free(sim->forks);
	free(sim->philos);
	free(sim);
}
