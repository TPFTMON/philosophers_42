/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 07:13:02 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/14 04:35:48 by abaryshe         ###   ########.fr       */
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
