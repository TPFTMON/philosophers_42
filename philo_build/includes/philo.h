/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 07:13:44 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/16 16:37:14 by abaryshe         ###   ########.fr       */
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
# define EXC_PARS 2

// --- File Descriptors ---
# define STDIN_FD 0
# define STDOUT_FD 1
# define STDERR_FD 2

// --- Messages ---
# define MSG_WRONG_AMNT_ARGS "\e[1;31mparsing error\e[0m:\
 wrong number of arguments\n"
# define MSG_USAGE_PHILO "\e[1;32m\nphilo usage\e[0m:\n\
./philo number_of_philosophers\
 time_to_die time_to_eat time_to_sleep [number_of_times_must_eat]\n"
# define MSG_ARG_POSITIVE "\e[1;31mparsing error\e[0m:\
 do not test with any argumet being zero or less\n"

# define MSG_ARG_PHILO "\e[1;33mcritical warning\e[0m:\
 do not test with more than 200 \e[1mphilosophers\e[0m\n"
# define MSG_ARG_TIME "\e[1;33mcritical warning\e[0m:\
 do not test with \e[1mtime_to_die\e[0m/\
\e[1mtime_to_eat\e[0m/\e[1mtime_to_sleep\e[0m being less than 60 ms\n"

# define MSG_ERROR_MEM "\e[1;31mcritical error\e[0m: memory failure"
# define MSG_ERROR_NO_TIME "\e[1;31mcritical error\e[0m: gettimeofday failed"

//   status messages:
# define FORK_MSG "has taken a fork"
# define EAT_STANSART_MSG "is eating"
# define EAT_WIN_MSG "\e[36mis eating\e[0m"
# define SLEEP_MSG "is sleeping"
# define THINK_MSG "is thinking"
# define DEAD_MSG "\e[1;31mdied\e[0m"
// # define WIN_MSG "all phisolophers have eaten their times_must_eat"

// --- Some Colors ---
# define RESET "\e[0m"
# define BOLD "\e[1m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define CYAN "\e[36m"

// <<<<<<<<<<<<<<<<<<<<< STRUCTURES >>>>>>>>>>>>>>>>>>>>>

struct	s_philo;

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
	bool				stop_flag;

	struct s_philo		*philos;
}						t_sim_data;

typedef struct s_philo
{
	int					id;
	long long			last_meal_time;
	int					meals_eaten;

	pthread_t			thread;

	pthread_mutex_t		personal_mutex;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;

	struct s_sim_data	*sim;
}						t_philo;

// <<<<<<<<<<<<<<<<<<<<< FUNCTIONS >>>>>>>>>>>>>>>>>>>>>

// philo.c
void					clear_simulation(t_sim_data *sim);
int						validate_input(int argc, char **argv);

// simulation.c
void					begin_simulation(t_sim_data *sim);
void					monitor_simulation(t_sim_data *sim);
bool					check_death(t_sim_data *sim);

// routine.c
void					*philo_routine(void *arg);
void					*single_philo_routine(void *arg);
//
void					eat_p(t_philo *philo, char *eat_message);
void					take_forks(t_philo *philo);
void					sleep_p(t_philo *philo);

// init.c
t_sim_data				*init_simulation(int argc, char **argv);
//
void					init_args(int argc, char **argv, t_sim_data *sim);
void					init_philos(t_sim_data *sim);
void					*free_forks_and_sim(t_sim_data *sim);

// libft_utils.c:
size_t					ft_strlen(const char *s);
char					*ft_strjoin(char const *s1, char const *s2);
int						print_error_with_code(char *object, char *msg,
							int error_code);
int						ft_atoi(const char *str);
int						ft_strcmp(const char *s1, const char *s2);

// utils.c
long long				get_current_ms(void);
void					print_philo_status(t_philo *philo, char *status);
bool					is_philo_dead(t_philo *philo);
bool					are_philos_full(t_sim_data *sim);
void					ft_usleep(long long ms, t_sim_data *sim);

// testing.c
// void					print_simulation_state(t_sim_data *sim);

#endif
