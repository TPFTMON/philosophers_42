/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:49:35 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/03 10:46:23 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_sim_data(int argc, char **argv, t_sim_data *sim)
{
	sim = malloc(sizeof(t_sim_data));
	if (!sim)
		return (print_error_with_code("philo", MSG_ERROR_MEM, FAIL));
	validate_args(argc, argv, sim);
	sim->start_time = get_current_ms();
	sim->dead_flag = 0;
}
