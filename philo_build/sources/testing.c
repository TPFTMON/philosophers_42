/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:12:37 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/05 13:41:33 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Prints a snapshot of the entire simulation state.
 * * This function displays the main parameters from the t_sim_data struct
 * and then lists each philosopher's state in a formatted table.
 * * @param sim A pointer to the main simulation data struct.
 */
void	print_simulation_state(t_sim_data *sim)
{
	int i;

	if (!sim)
	{
		printf(BOLD "Error: Simulation data is NULL.\n" RESET);
		return;
	}
	printf(BOLD GREEN "=============================================\n" RESET);
	printf(BOLD GREEN "      SIMULATION STATE SNAPSHOT\n" RESET);
	printf(BOLD GREEN "=============================================\n" RESET);
	printf(CYAN " num_of_philos:  " RESET "%d\n", sim->num_of_philos);
	printf(CYAN " time_to_die:    " RESET "%d ms\n", sim->time_to_die);
	printf(CYAN " time_to_eat:    " RESET "%d ms\n", sim->time_to_eat);
	printf(CYAN " time_to_sleep:  " RESET "%d ms\n", sim->time_to_sleep);
	if (sim->times_must_eat != -1)
		printf(CYAN " times_must_eat: " RESET "%d\n", sim->times_must_eat);
	else
		printf(CYAN " times_must_eat: " RESET "Not set\n");
	printf("---------------------------------------------\n");
	printf(CYAN " start_time:     " RESET "%lld\n", sim->start_time);
	printf(CYAN " dead_flag:      " RESET "%s\n", sim->dead_flag ? "true (1)" : "false (0)");
	printf(CYAN " forks addr:     " RESET "%p\n", (void *)sim->forks);
	printf(CYAN " philos addr:    " RESET "%p\n", (void *)sim->philos);
	printf(BOLD GREEN "---------------------------------------------\n\n" RESET);
	if (sim->philos)
	{
		printf(BOLD YELLOW "-------------------------------------------------------------------------------------------------\n" RESET);
		printf(BOLD YELLOW "| %-5s | %-18s | %-12s | %-18s | %-18s |\n", "Philo", "Last Meal Time", "Meals Eaten", "Left Fork Addr", "Right Fork Addr");
		printf(BOLD YELLOW "-------------------------------------------------------------------------------------------------\n" RESET);
		i = 0;
		while (i < sim->num_of_philos)
		{
			printf("| %-5d | %-18lld | %-12d | %-18p | %-18p |\n",
				sim->philos[i].id,
				sim->philos[i].last_meal_time,
				sim->philos[i].meals_eaten,
				(void *)sim->philos[i].left_fork,
				(void *)sim->philos[i].right_fork);
			i++;
		}
		printf(BOLD YELLOW "-------------------------------------------------------------------------------------------------\n" RESET);
	}
	else
		printf(BOLD "Philosopher data not initialized.\n" RESET);
}

// /*
//  * Helper: safe fork-index retrieval.
//  * Returns -1 if sim->forks is NULL or the pointer isn't inside that array.
//  */
// static int get_fork_index(t_sim_data *sim, pthread_mutex_t *fork_ptr)
// {
//     if (!sim || !sim->forks || !fork_ptr)
//         return -1;
//     ptrdiff_t idx = fork_ptr - sim->forks; /* pointer arithmetic */
//     if (idx < 0 || (size_t)idx >= (size_t)sim->num_of_philos)
//         return -1;
//     return (int)idx;
// }

// /*
//  * Pretty-print the whole simulation structure and all philosophers.
//  * Call this only after sim is initialized (print_mutex created).
//  */
// void print_simulation_state(t_sim_data *sim)
// {
//     int i;

//     if (!sim)
//     {
//         printf("[debug] sim is NULL\n");
//         return;
//     }

//     /* Try to serialize output to avoid scrambled logs if threads are active.
//        If print_mutex is not initialized, this will deadlock/UB — so only call
//        after sim init in normal usage. */
//     pthread_mutex_lock(&sim->print_mutex);

//     printf("\n");
//     printf("┌────────────────────────────── Simulation summary ──────────────────────────────┐\n");
//     printf("│ philosophers : %4d   | time_to_die  : %6d ms   | time_to_eat  : %6d ms       │\n",
//            sim->num_of_philos, sim->time_to_die, sim->time_to_eat);
//     printf("│ time_to_sleep: %6d ms   | times_must_eat: %6d   | start_time(ms): %12lld │\n",
//            sim->time_to_sleep, sim->times_must_eat, (long long)sim->start_time);
//     printf("│ dead_flag    : %6s   | forks addr    : %p                                     │\n",
//            sim->dead_flag ? "true" : "false", (void *)sim->forks);
//     printf("└───────────────────────────────────────────────────────────────────────────────┘\n\n");

//     printf("┌────┬────────────┬────────────┬────────────┬──────────────┬─────────────────────┐\n");
//     printf("│ id │ last_meal  │ last_relms │ meals_eaten│ left_fork_ix │ right_fork_ix/thread│\n");
//     printf("├────┼────────────┼────────────┼────────────┼──────────────┼─────────────────────┤\n");

//     for (i = 0; i < sim->num_of_philos; i++)
//     {
//         t_philo *p = &sim->philos[i];
//         long long last = p->last_meal_time;
//         long long rel = (sim->start_time > 0) ? (last - sim->start_time) : last;
//         int left_idx = get_fork_index(sim, p->left_fork);
//         int right_idx = get_fork_index(sim, p->right_fork);

//         /* Print thread id as unsigned long long for debugging visibility */
//         unsigned long long tid = (unsigned long long)p->thread;

//         printf("│ %2d │ %10lld │ %10lld │ %10d │ %12s │ %6s / TID:%#010llx │\n",
//                p->id,
//                (long long)last,
//                (long long)rel,
//                p->meals_eaten,
//                (left_idx >= 0 ? (char[16]){0} : (char[16]){0}), /* placeholder for alignment */
//                (right_idx >= 0 ? (char[6]){0} : (char[6]){0}),
//                tid);

//         /* Because C doesn't allow inline construction in printf easily, do a second
//            print with clearer fork indices and addresses. */
//         printf("     forks: left=%3d (%p)  right=%3d (%p)\n",
//                left_idx, (void *)p->left_fork, right_idx, (void *)p->right_fork);
//     }

//     printf("└────┴────────────┴────────────┴────────────┴──────────────┴─────────────────────┘\n\n");

//     pthread_mutex_unlock(&sim->print_mutex);
// }
