/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 07:13:02 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/03 11:18:40 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	// t_sim_data	*sim;

	if (validate_input(argc, argv) != SUCCESS)
		return (EXC_PARSING);
	printf("\e[1;35mReady to perform!\e[0m\n");
	// init_sim_data(argc, argv, sim);
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
