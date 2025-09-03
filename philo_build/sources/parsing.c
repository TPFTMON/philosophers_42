/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:03:26 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/03 11:27:08 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		print_error_with_code("philo", MSG_WRONG_AMNT_ARGS, EXC_PARSING);
		return (print_error_with_code(NULL, MSG_USAGE_PHILO, EXC_PARSING));
	}
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
			return (print_error_with_code("philo", "WRONG!\n", EXC_PARSING));
		// printf("arg[%d]: %d\n", i, ft_atoi(argv[i]));
		i++;
	}
	return (SUCCESS);
}
