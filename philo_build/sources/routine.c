/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:53:55 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/12 22:05:09 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_p(t_philo *philo);
void	take_forks(t_philo *philo);
void	sleep_p(t_philo *philo);
void	think_p(t_philo *philo);

	/*
routine:
	while (1)
		1. eat:
			1.1. Take forks. (with some anti-deadlock tech)
			1.2. usleep for "time_to_eat" ms.
			1.3. Put forks down.

		2. sleep:
			2.1 usleep for "time_to_sleep" ms.

		3. think
	*/
void	*philo_routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	think_p(philo);
	while (1)
	{
		pthread_mutex_lock(&philo->sim->stop_mutex);
		if (philo->sim->stop_flag)
		{
			pthread_mutex_unlock(&philo->sim->stop_mutex);
			// print_philo_status(philo, DEAD_MSG);
			break ;
		}
		pthread_mutex_unlock(&philo->sim->stop_mutex);
		eat_p(philo);
		sleep_p(philo);
		think_p(philo);
	}
	return (NULL);
}

	/*
	1. Take both forks (using the odd/even strategy).

	2. Lock the personal meal_lock.

	3. Update last_meal_time to the current time and increment meals_eaten.

	4. Unlock the personal meal_lock.

	5. Report "is eating" (using the print_mutex).

	6. usleep for time_to_eat.

	7. Release both forks.
	*/
void	eat_p(t_philo *philo)
{
	// if (philo->id == 1)
	// {
	// 	pthread_mutex_lock(philo->left_fork);
	// 	print_philo_status(philo, FORK_MSG);
	// 	return ;
	// }
	take_forks(philo);

	pthread_mutex_lock(&philo->personal_mutex);
	philo->last_meal_time = get_current_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->personal_mutex);

	print_philo_status(philo, EAT_MSG);

	usleep(philo->sim->time_to_eat * 1000);

	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_philo_status(philo, FORK_MSG);
		pthread_mutex_lock(philo->right_fork);
		print_philo_status(philo, FORK_MSG);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_philo_status(philo, FORK_MSG);
		pthread_mutex_lock(philo->left_fork);
		print_philo_status(philo, FORK_MSG);
	}
}

void	sleep_p(t_philo *philo)
{
	print_philo_status(philo, SLEEP_MSG);
	usleep(philo->sim->time_to_sleep * 1000);
}

void	think_p(t_philo *philo)
{
	print_philo_status(philo, THINK_MSG);
}






























// void	*philo_routine(void	*arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)arg;

// 	// A simple loop where the philosopher just thinks.
// 	// In my final code, this will be the eat/sleep/think cycle.
// 	while (1) // This will later be controlled by the stop_flag
// 	{
// 		// Use the safe printing function
// 		print_philo_status(philo, THINK_MSG);

// 		// Wait a bit before thinking again
// 		usleep(500 * 1000); // Sleep for 500ms

// 		// In your real code, you'd check the stop_flag here to break the loop
// 		pthread_mutex_lock(&philo->sim->stop_mutex);
// 		// philo->sim->stop_flag = 1;
// 		if (philo->sim->stop_flag)
// 		{
// 			pthread_mutex_unlock(&philo->sim->stop_mutex);
// 			// print_philo_status(philo, DEAD_MSG);
// 			break;
// 		}
// 		pthread_mutex_unlock(&philo->sim->stop_mutex);
// 	}
// 	return (NULL);
// }

