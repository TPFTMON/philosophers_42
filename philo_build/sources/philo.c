/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 07:13:02 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/12 21:10:17 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	begin_simulation(t_sim_data *sim);
// void	monitor_simulation(t_sim_data *sim);

int main(int argc, char **argv)
{
	t_sim_data	*sim;

	if (validate_input(argc, argv) != SUCCESS)
		return (EXC_PARSING);
	printf(BOLD"\e[4;32mReady to init!\e[0m\n");

	sim = init_simulation(argc, argv);
	if (!sim)
		return (print_error_with_code("philo", MSG_ERROR_MEM, EXC_CRIT));
	printf(BOLD"\e[4;32mReady to start!\e[0m\n");

	print_simulation_state(sim);

	begin_simulation(sim);
	printf(BOLD"\e[4;32mReady to monitor!\e[0m\n");

	monitor_simulation(sim);
	printf(BOLD"\e[4;32mReady to clean up!\e[0m\n");

	clear_simulation(sim);
	printf(BOLD"\e[4;32mSimulation has been cleared up!\e[0m\n");
	return (0);
}
