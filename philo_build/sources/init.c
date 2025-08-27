/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:49:35 by abaryshe          #+#    #+#             */
/*   Updated: 2025/08/27 16:24:45 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_ms(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		print_error_with_code("philo", MSG_ERROR_NO_TIME, 1);
	return (tv.tv_sec * 1000LL + tv.tv_usec * 1000LL);
}

void	init_sim_data(t_sim_data *sim)
{
	sim = malloc(sizeof(t_sim_data));
	if (!sim)
		return (print_error_with_code("philo", MSG_ERROR_MEM, 1));
	sim->start_time = get_current_ms();
	sim->dead_flag = 0;
}
