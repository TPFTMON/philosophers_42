/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 07:13:44 by abaryshe          #+#    #+#             */
/*   Updated: 2025/08/11 21:02:25 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// <<<<<<<<<<<<<<<<<<<<< INCLUDES >>>>>>>>>>>>>>>>>>>>>

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

// <<<<<<<<<<<<<<<<<<<<< MACROS >>>>>>>>>>>>>>>>>>>>>

// --- File Descriptors ---
# define STDIN_FD 0
# define STDOUT_FD 1
# define STDERR_FD 2

// --- Messages ---

# define MSG_WRONG_AMNT_ARGS "\e[0;31mparsing error\e[0m: wrong number of arguments.\n"
# define MSG_USAGE_PHILO "\e[1;32m\nThe philo usage\e[0m:\n./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_must_eat]\n"

// <<<<<<<<<<<<<<<<<<<<< STRUCTURES >>>>>>>>>>>>>>>>>>>>>

typedef struct s_philo
{

}	t_philo;

typedef struct s_sim
{

}	t_sim;

// <<<<<<<<<<<<<<<<<<<<< FUNCTIONS >>>>>>>>>>>>>>>>>>>>>

// error.c:

// libft_utils.c:
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int	print_error_with_code(char *object, char *msg, int error_code);

#endif
