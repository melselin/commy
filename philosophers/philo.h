/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:52:26 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/05/04 00:22:41 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define R "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define C "\033[1;36m"
# define RESET "\033[0m"
/* norminette doesnt love colors >:(
# define MSG_DEATH R "%lld %d died" RESET "\n"
# define MSG_EAT G "%lld %d is eating" RESET "\n"
# define MSG_SLEEP B "%lld %d is sleeping" RESET "\n"
# define MSG_THINK Y "%lld %d is thinking" RESET "\n"
# define MSG_FORK C "%lld %d has taken a fork" RESET "\n"
# define MSG_ALL_ATE G "%lld All philosophers ate at least %d times" RESET "\n"
*/
# define MSG_DEATH "%lld %d died\n"
# define MSG_EAT "%lld %d is eating\n"
# define MSG_SLEEP "%lld %d is sleeping\n"
# define MSG_THINK "%lld %d is thinking\n"
# define MSG_FORK "%lld %d has taken a fork\n"
# define MSG_ALL_ATE "%lld All philosophers have eaten at least %d times\n"

typedef struct s_rules	t_rules;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long long		last_meal;
	int				meals_eaten;
	pthread_t		thread_id;
	t_rules			*rules;
}					t_philo;

typedef struct s_rules
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	bool			died;
	bool			all_ate;
	long long		start_time;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	writing;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_rules;

int			main(int argc, char **argv);
int			handle_single_philo(t_rules *rules);

int			init_main_mutexes(t_rules *rules);
int			init_forks_mutexes(t_rules *rules);
void		cleanup_partial_init(t_rules *rules, int forks_init_count);
int			init_mutexes(t_rules *rules);
int			init_philosophers(t_rules *rules);
int			init_all(t_rules *rules, char **argv);
void		cleanup(t_rules *rules);

long long	timestamp(void);
void		precise_usleep(long long time_ms);

void		*routine(void *void_philo);
void		take_forks(t_philo *philo);
void		eat(t_philo *philo);
void		drop_forks(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		think(t_philo *philo);

bool		check_death(t_rules *rules, int i);
bool		check_all_ate(t_rules *rules);
void		*monitor(void *void_rules);

void		print_action(t_rules *rules, int id, char *str);
int			error_exit(char *str);
int			ft_atoi(const char *str);
bool		is_valid_input(int argc, char **argv);
int			ft_strcmp(const char *s1, const char *s2);

#endif
