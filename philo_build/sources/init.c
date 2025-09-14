/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:49:35 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/15 01:38:41 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_sim_data	*init_simulation(int argc, char **argv)
{
	t_sim_data	*sim;

	sim = malloc(sizeof(t_sim_data));
	if (!sim)
		return (NULL);
	init_args(argc, argv, sim);
	sim->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* sim->num_of_philos);
	if (!sim->forks)
		return (free_forks_and_sim(sim));
	sim->philos = (t_philo *)malloc(sizeof(t_philo) * sim->num_of_philos);
	if (!sim->philos)
		return (free_forks_and_sim(sim));
	pthread_mutex_init(&sim->print_mutex, NULL);
	pthread_mutex_init(&sim->stop_mutex, NULL);
	sim->start_time = get_current_ms();
	sim->stop_flag = 0;
	init_philos(sim);
	return (sim);
}

void	init_args(int argc, char **argv, t_sim_data *sim)
{
	sim->num_of_philos = ft_atoi(argv[1]);
	sim->time_to_die = ft_atoi(argv[2]);
	sim->time_to_eat = ft_atoi(argv[3]);
	sim->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		sim->times_must_eat = ft_atoi(argv[5]);
	else
		sim->times_must_eat = -1;
}

void	init_philos(t_sim_data *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_of_philos)
	{
		pthread_mutex_init(&sim->philos[i].personal_mutex, NULL);
		pthread_mutex_init(&sim->forks[i], NULL);
		sim->philos[i].id = i + 1;
		sim->philos[i].last_meal_time = sim->start_time;
		sim->philos[i].meals_eaten = 0;
		sim->philos[i].left_fork = &sim->forks[i];
		sim->philos[i].right_fork = &sim->forks[(i + 1) % sim->num_of_philos];
		sim->philos[i].sim = sim;
		sim->philos[i].thread = 0;
		i++;
	}
}

void	*free_forks_and_sim(t_sim_data *sim)
{
	if (!sim)
		return (NULL);
	if (sim->forks)
		free(sim->forks);
	free(sim);
	return (NULL);
}
