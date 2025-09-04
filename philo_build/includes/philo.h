/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 07:13:44 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/04 19:28:40 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// <<<<<<<<<<<<<<<<<<<<< INCLUDES >>>>>>>>>>>>>>>>>>>>>

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// <<<<<<<<<<<<<<<<<<<<< MACROS >>>>>>>>>>>>>>>>>>>>>

// --- General ---
# define SUCCESS 0
# define FAIL 1

// --- Exit Codes ---
# define EXC_OK 0
# define EXC_CRIT 1
# define EXC_PARSING 2

// --- File Descriptors ---
# define STDIN_FD 0
# define STDOUT_FD 1
# define STDERR_FD 2

// --- Messages ---
# define MSG_WRONG_AMNT_ARGS "\e[1;31mparsing error\e[0m: wrong number of arguments\n"
# define MSG_USAGE_PHILO "\e[1;32m\nThe philo usage\e[0m:\n./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_must_eat]\n"

# define MSG_ERROR_MEM "\e[1;31mcritical error\e[0m: memory failure"
# define MSG_ERROR_NO_TIME "\e[1;31mcritical error\e[0m: gettimeofday failed"

// <<<<<<<<<<<<<<<<<<<<< STRUCTURES >>>>>>>>>>>>>>>>>>>>>

struct s_philo;

typedef struct s_sim_data
{
	int					num_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_must_eat;

	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		stop_mutex;
	long long			start_time;
	bool				dead_flag;

	struct s_philo		*philos;
}						t_sim_data;

typedef struct s_philo
{
	int					id;
	long long			last_meal_time;
	int					meals_eaten;

	pthread_t			thread;

	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;

	struct s_sim_data	*sim;
}						t_philo;

// <<<<<<<<<<<<<<<<<<<<< FUNCTIONS >>>>>>>>>>>>>>>>>>>>>

// cleanup.c
void					clear_simulation(t_sim_data *sim);

// parsing.c
int						validate_input(int argc, char **argv);

// init.c
t_sim_data				*init_sim_data(int argc, char **argv);

// libft_utils.c:
size_t					ft_strlen(const char *s);
char					*ft_strjoin(char const *s1, char const *s2);
int						print_error_with_code(char *object, char *msg,
							int error_code);
int						ft_atoi(const char *str);

// utils.c
long long				get_current_ms(void);

#endif
