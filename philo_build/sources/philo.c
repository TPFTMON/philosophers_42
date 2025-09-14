/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 07:13:02 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/15 01:44:37 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_sim_data	*sim;

	if (validate_input(argc, argv) != SUCCESS)
		return (EXC_PARS);
	sim = init_simulation(argc, argv);
	if (!sim)
		return (print_error_with_code("philo", MSG_ERROR_MEM, EXC_CRIT));
	begin_simulation(sim);
	monitor_simulation(sim);
	clear_simulation(sim);
	return (0);
}

int	validate_input(int argc, char **argv)
{
	int	i;
	int	return_code;

	return_code = SUCCESS;
	if (argc < 5 || argc > 6)
	{
		print_error_with_code("philo", MSG_WRONG_AMNT_ARGS, EXC_PARS);
		return (print_error_with_code(NULL, MSG_USAGE_PHILO, EXC_PARS));
	}
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			return_code = print_error_with_code("philo", MSG_ARG_POSITIVE,
					EXC_PARS);
			break ;
		}
		i++;
	}
	if (ft_atoi(argv[1]) > 200)
		return_code = print_error_with_code("philo", MSG_ARG_PHILO, EXC_PARS);
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return_code = print_error_with_code("philo", MSG_ARG_TIME, EXC_PARS);
	return (return_code);
}

void	clear_simulation(t_sim_data *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_of_philos)
	{
		if (sim->philos[i].thread)
			pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < sim->num_of_philos)
	{
		if (&sim->philos[i])
			pthread_mutex_destroy(&sim->philos[i].personal_mutex);
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
