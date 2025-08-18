/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 07:13:02 by abaryshe          #+#    #+#             */
/*   Updated: 2025/08/18 18:36:51 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_sim_data	sim;

	(void)argv;
	if (argc < 5 || argc > 6)
	{
		print_error_with_code("philo", MSG_WRONG_AMNT_ARGS, 1);
		return (print_error_with_code(NULL, MSG_USAGE_PHILO, 1));
	}
	printf("\e[1;35mReady to perform!\e[0m\n");
	init_sim_data(argc, argv, sim);
	parse_imput(argc, argv);
	return (0);
}
