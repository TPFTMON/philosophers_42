/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:53:55 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/05 17:37:15 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_p();

void	think_p();

void	sleep_p();

void	*philo_routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	// A simple loop where the philosopher just thinks.
	// In my final code, this will be the eat/sleep/think cycle.
	while (1) // This will later be controlled by the dead_flag
	{
		// Use the safe printing function
		print_status(philo, THINK_MSG);

		// Wait a bit before thinking again
		usleep(500 * 1000); // Sleep for 500ms

		// In your real code, you'd check the dead_flag here to break the loop
		pthread_mutex_lock(&philo->sim->stop_mutex);
		// philo->sim->dead_flag = 1;
		if (philo->sim->dead_flag)
		{
			pthread_mutex_unlock(&philo->sim->stop_mutex);
			// print_status(philo, DEAD_MSG);
			break;
		}
		pthread_mutex_unlock(&philo->sim->stop_mutex);
	}
	return (NULL);
}

// void	philo_routine(void	*arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)arg;


// 	/*
// routine:
// 	while (1)
// 		||
// 		\/
// 		1. eat:
// 			1.1. Take forks. (with some anti-deadlock tech)
// 			1.2. usleep for "time_to_eat" ms.
// 			1.3. Put forks down.
// 		||
// 		\/
// 		2. sleep:
// 			2.1 usleep for "time_to_sleep" ms.
// 		||
// 		\/
// 		3. think:
// 			3.1. (wait for forks to eat)
// 		||
// 		\/
// 	*/
// }

void	run_simulation(t_sim_data *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_of_philos)
	{
		pthread_create(&sim->philos[i].thread, NULL, philo_routine, &sim->philos[i]);
		i++;
	}
}
