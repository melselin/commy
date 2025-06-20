/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:52:11 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/05/03 23:53:09 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philosophers(t_rules *rules)
{
	int	i;

	rules->philos = malloc(sizeof(t_philo) * rules->philo_count);
	if (!rules->philos)
		return (1);
	i = 0;
	while (i < rules->philo_count)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].left_fork = i;
		rules->philos[i].right_fork = (i + 1) % rules->philo_count;
		rules->philos[i].last_meal = rules->start_time;
		rules->philos[i].meals_eaten = 0;
		rules->philos[i].rules = rules;
		i++;
	}
	return (0);
}

int	init_all(t_rules *rules, char **argv)
{
	rules->philo_count = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	rules->must_eat_count = -1;
	if (argv[5])
		rules->must_eat_count = ft_atoi(argv[5]);
	rules->died = false;
	rules->all_ate = false;
	rules->start_time = timestamp();
	if (rules->philo_count < 1 || rules->philo_count > 200
		|| rules->time_to_die < 60 || rules->time_to_eat < 60
		|| rules->time_to_sleep < 60
		|| (argv[5] && rules->must_eat_count < 0))
		return (error_exit("Error: Invalid arguments"));
	if (init_mutexes(rules))
		return (error_exit("Error: Mutex initialization failed"));
	if (init_philosophers(rules))
	{
		cleanup(rules);
		return (error_exit("Error: Philosophers initialization failed"));
	}
	return (0);
}

void	cleanup(t_rules *rules)
{
	int	i;

	if (rules->forks)
	{
		i = 0;
		while (i < rules->philo_count)
		{
			pthread_mutex_destroy(&rules->forks[i]);
			i++;
		}
		free(rules->forks);
	}
	if (rules->philos)
		free(rules->philos);
	pthread_mutex_destroy(&rules->writing);
	pthread_mutex_destroy(&rules->meal_check);
}
