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

int	init_main_mutexes(t_rules *rules)
{
	int	ret;

	ret = pthread_mutex_init(&rules->writing, NULL);
	if (ret != 0)
		return (1);
	ret = pthread_mutex_init(&rules->meal_check, NULL);
	if (ret != 0)
	{
		pthread_mutex_destroy(&rules->writing);
		return (1);
	}
	return (0);
}

int	init_forks_mutexes(t_rules *rules)
{
	int	i;

	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->philo_count);
	if (!rules->forks)
		return (1);
	i = 0;
	while (i < rules->philo_count)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
			break ;
		i++;
	}
	return (i);
}

void	cleanup_partial_init(t_rules *rules, int forks_init_count)
{
	int	i;

	i = 0;
	while (i < forks_init_count)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	free(rules->forks);
	pthread_mutex_destroy(&rules->writing);
	pthread_mutex_destroy(&rules->meal_check);
}

int	init_mutexes(t_rules *rules)
{
	int	forks_init_count;
	int	ret;

	ret = init_main_mutexes(rules);
	if (ret != 0)
		return (1);
	forks_init_count = init_forks_mutexes(rules);
	if (forks_init_count != rules->philo_count)
	{
		if (forks_init_count > 0)
			cleanup_partial_init(rules, forks_init_count);
		else
		{
			free(rules->forks);
			pthread_mutex_destroy(&rules->writing);
			pthread_mutex_destroy(&rules->meal_check);
		}
		return (1);
	}
	return (0);
}
