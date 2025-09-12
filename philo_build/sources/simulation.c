/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:11:18 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/12 21:57:15 by abaryshe         ###   ########.fr       */
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
		usleep(1000);
		i++;
	}
}

/*
monitor:
	whiel(1)
		1. checks if a philo has died
			if yes ->
				write the stop_flag and break
		2. checks if all philos have eaten times_must_eat
			if yes ->
				write the stop_flag and break
*/
void	monitor_simulation(t_sim_data *sim)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < sim->num_of_philos)
		{
			if (is_philo_dead(&sim->philos[i]))
			{
			    pthread_mutex_lock(&sim->stop_mutex);
			    if (sim->stop_flag == false) // Check again inside the lock
			    {
			        sim->stop_flag = true;
			        // Print the final message while holding the stop lock
			        print_philo_status(&sim->philos[i], DEAD_MSG);
			    }
			    pthread_mutex_unlock(&sim->stop_mutex);
			    return ;
			}
			i++;
		}
		if (are_philos_full(sim))
		{
			pthread_mutex_lock(&sim->stop_mutex);
		    sim->stop_flag = true;
		    pthread_mutex_unlock(&sim->stop_mutex);
			return ;
		}
		usleep(1000);
	}
}
