/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 07:13:44 by abaryshe          #+#    #+#             */
/*   Updated: 2025/08/18 18:34:55 by abaryshe         ###   ########.fr       */
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
# include <stdbool.h>

// <<<<<<<<<<<<<<<<<<<<< MACROS >>>>>>>>>>>>>>>>>>>>>

// --- File Descriptors ---
# define STDIN_FD 0
# define STDOUT_FD 1
# define STDERR_FD 2

// --- Messages ---

# define MSG_WRONG_AMNT_ARGS "\e[0;31mparsing error\e[0m: wrong number of arguments.\n"
# define MSG_USAGE_PHILO "\e[1;32m\nThe philo usage\e[0m:\n./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_must_eat]\n"

// <<<<<<<<<<<<<<<<<<<<< STRUCTURES >>>>>>>>>>>>>>>>>>>>>

struct s_philo;

typedef struct s_sim_data
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;

	long long	start_time;
	pthread_mutex_t	forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
	bool	dead_flag;

	struct philo	*philos;
}	t_sim_data;

typedef struct s_philo
{
	int	id;
	int	meals_eaten;
	long long last_meal_time;

	pthread_t	thread;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	struct s_sim_data	sim;
}	t_philo;

// <<<<<<<<<<<<<<<<<<<<< FUNCTIONS >>>>>>>>>>>>>>>>>>>>>

// error.c:

// libft_utils.c:
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int	print_error_with_code(char *object, char *msg, int error_code);

#endif
