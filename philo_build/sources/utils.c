/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:19:45 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/15 01:17:53 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief usleep but BETTER. (more precise)
 *
 * This function suspends execution of the calling thread
 * FOR ms given.
 * Uses sim to carefully track/check when to stop
 * suspending. (In case of a philo's death/win)
 *
 * @param ms The milliseconds to suspend for.
 * @param sim The main data struct.
 * @return void
 */
void	ft_usleep(long long ms, t_sim_data *sim)
{
	long long	start;

	start = get_current_ms();
	while (1)
	{
		pthread_mutex_lock(&sim->stop_mutex);
		if (sim->stop_flag)
		{
			pthread_mutex_unlock(&sim->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&sim->stop_mutex);
		if (get_current_ms() - start >= ms)
			break ;
		usleep(500);
	}
}

long long	get_current_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		print_error_with_code("philo", MSG_ERROR_NO_TIME, 1);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000LL);
}

void	print_philo_status(t_philo *philo, char *status)
{
	long long	current_time;
	bool		should_print;

	should_print = false;
	pthread_mutex_lock(&philo->sim->stop_mutex);
	if (!philo->sim->stop_flag || ft_strcmp(status, DEAD_MSG) == 0)
		should_print = true;
	pthread_mutex_unlock(&philo->sim->stop_mutex);
	if (should_print)
	{
		current_time = get_current_ms() - philo->sim->start_time;
		pthread_mutex_lock(&philo->sim->print_mutex);
		printf("%lld %d %s\n", current_time, philo->id, status);
		pthread_mutex_unlock(&philo->sim->print_mutex);
	}
}

bool	is_philo_dead(t_philo *philo)
{
	long long	current_time;
	long long	time_since_last_meal;

	pthread_mutex_lock(&philo->personal_mutex);
	current_time = get_current_ms();
	time_since_last_meal = current_time - philo->last_meal_time;
	pthread_mutex_unlock(&philo->personal_mutex);
	if (time_since_last_meal >= philo->sim->time_to_die)
		return (true);
	return (false);
}

bool	are_philos_full(t_sim_data *sim)
{
	int	i;
	int	how_many_meals;

	if (sim->times_must_eat <= 0)
		return (false);
	i = 0;
	while (i < sim->num_of_philos)
	{
		pthread_mutex_lock(&sim->philos[i].personal_mutex);
		how_many_meals = sim->philos[i].meals_eaten;
		pthread_mutex_unlock(&sim->philos[i].personal_mutex);
		if (how_many_meals < sim->times_must_eat)
			return (false);
		i++;
	}
	return (true);
}

// void	ft_usleep(long long ms, t_sim_data *sim)
// // {
// long long	start;
//
// start = get_current_ms();
// pthread_mutex_lock(&sim->stop_mutex);
// while (!sim->stop_flag)
// {
// pthread_mutex_unlock(&sim->stop_mutex);
// if (get_current_ms() - start >= ms)
// return ;
// usleep(100);
// pthread_mutex_lock(&sim->stop_mutex);
// }
// pthread_mutex_unlock(&sim->stop_mutex);
// }

// void	print_philo_status(t_philo *philo, char *status)
// {
// 	long long	current_time;

// 	pthread_mutex_lock(&philo->sim->stop_mutex);
// 	if (!philo->sim->stop_flag || ft_strcmp(status, DEAD_MSG) == 0)
// 	{
// 		pthread_mutex_unlock(&philo->sim->stop_mutex);
// 		current_time = get_current_ms() - philo->sim->start_time;
// 		pthread_mutex_lock(&philo->sim->print_mutex);
// 		printf("%lld %d %s\n", current_time, philo->id, status);
// 		pthread_mutex_unlock(&philo->sim->print_mutex);
// 		return ;
// 	}
// 	pthread_mutex_unlock(&philo->sim->stop_mutex);
// }

// int	main(void)
// {
// 	struct timeval	tv;
// 	long			milliseconds;

// 	if (gettimeofday(&tv, NULL) == -1)
// 	{
// 		printf("gettimeofday failed\n");
// 		return (1);
// 	}
// 	milliseconds = (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
// 	printf("current ms: [%lld]\n", get_current_ms());
// 	printf("Current time in ms: %ld\n", milliseconds);
// 	return (0);
// }
