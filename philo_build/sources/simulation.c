/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:11:18 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/09 16:44:18 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	begin_simulation(t_sim_data *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_of_philos)
	{
		pthread_create(&sim->philos[i].thread, NULL, philo_routine, &sim->philos[i]);
		i++;
	}
}

void	monitor_simulation()
{
	
}

// void	begin_simulation(t_sim_data *sim)
// {
// 	int	i;

// 	i = 0;
// 	while (i < sim->num_of_philos)
// 	{
// 		pthread_create(&sim->philos[i].thread, NULL, philo_routine, &sim->philos[i]);
// 		i++;
// 	}
// }
