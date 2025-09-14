/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:03:26 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/14 03:52:57 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_input(int argc, char **argv)
{
	int	i;
	int	return_code;

	return_code = SUCCESS;
	if (argc < 5 || argc > 6)
	{
		print_error_with_code("philo", MSG_WRONG_AMNT_ARGS, EXC_PARSING);
		return (print_error_with_code(NULL, MSG_USAGE_PHILO, EXC_PARSING));
	}
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			return_code = print_error_with_code("philo", MSG_ARG_POSITIVE, EXC_PARSING);
			break ;
		}
		i++;
	}
	if (ft_atoi(argv[1]) > 200)
		return_code = print_error_with_code("philo", MSG_ARG_PHILO, EXC_PARSING);
	if (ft_atoi(argv[2]) < 20 || ft_atoi(argv[3]) < 20 || ft_atoi(argv[4]) < 20)
		return_code = print_error_with_code("philo", MSG_ARG_TIME, EXC_PARSING);
	return (return_code);
}

// int	validate_input(int argc, char **argv)
// {
	// int	i;
//
	// if (argc < 5 || argc > 6)
	// {
		// print_error_with_code("philo", MSG_WRONG_AMNT_ARGS, EXC_PARSING);
		// return (print_error_with_code(NULL, MSG_USAGE_PHILO, EXC_PARSING));
	// }
	// i = 1;
	// while (argv[i])
	// {
		// if (ft_atoi(argv[i]) <= 0)
			// return (print_error_with_code("philo", "\e[1;31mWRONG!\e[0m\n", EXC_PARSING));
		// printf("arg[%d]: %d\n", i, ft_atoi(argv[i]));
		// i++;
	// }
	// return (SUCCESS);
// }
