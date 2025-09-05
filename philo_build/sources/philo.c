/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 07:13:02 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/05 14:12:36 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_sim_data	*sim;

	if (validate_input(argc, argv) != SUCCESS)
		return (EXC_PARSING);
	printf(BOLD"\e[4;32mReady to init!\e[0m\n");
	sim = init_sim_data(argc, argv);
	if (!sim)
		return (print_error_with_code("philo", MSG_ERROR_MEM, EXC_CRIT));

	printf(BOLD"\e[4;32mReady to start!\e[0m\n");
	print_simulation_state(sim);

	// philo_routine(sim);

	clear_simulation(sim);
	printf(BOLD"\e[4;32mSimulation has been cleaned up!\e[0m\n");
	return (0);
}

// int main() {
//     struct timeval tv;
//     if (gettimeofday(&tv, NULL) == -1) {
//         printf("gettimeofday failed\n");
//         return 1;
//     }

//     long milliseconds = (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
//     printf("Current time in ms: %ld\n", milliseconds);
//     return 0;
// }
