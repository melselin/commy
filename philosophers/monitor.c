/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:52:22 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/05/04 00:01:18 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_death(t_rules *rules, int i)
{
	long long	current;
	long long	last_meal;
	bool		died;

	pthread_mutex_lock(&rules->meal_check);
	current = timestamp();
	last_meal = rules->philos[i].last_meal;
	died = (current - last_meal) >= rules->time_to_die;
	if (died && !rules->died && !rules->all_ate)
	{
		rules->died = true;
		pthread_mutex_lock(&rules->writing);
		printf(MSG_DEATH, current - rules->start_time, rules->philos[i].id);
		pthread_mutex_unlock(&rules->writing);
	}
	pthread_mutex_unlock(&rules->meal_check);
	return (died);
}

static void	handle_all_ate(t_rules *rules)
{
	rules->all_ate = true;
	pthread_mutex_lock(&rules->writing);
	printf(MSG_ALL_ATE, timestamp() - rules->start_time,
		rules->must_eat_count);
	pthread_mutex_unlock(&rules->writing);
}

bool	check_all_ate(t_rules *rules)
{
	int		i;
	bool	all_ate;

	if (rules->must_eat_count == -1)
		return (false);
	all_ate = true;
	pthread_mutex_lock(&rules->meal_check);
	i = -1;
	while (++i < rules->philo_count)
	{
		if (rules->philos[i].meals_eaten < rules->must_eat_count)
		{
			all_ate = false;
			break ;
		}
	}
	if (all_ate && !rules->died)
		handle_all_ate(rules);
	pthread_mutex_unlock(&rules->meal_check);
	return (all_ate);
}

void	*monitor(void *void_rules)
{
	t_rules		*rules;
	int			i;
	long long	start;
	long long	current;

	rules = (t_rules *)void_rules;
	start = timestamp();
	while (!rules->died && !rules->all_ate)
	{
		current = timestamp();
		if (current - start >= 5)
		{
			i = -1;
			while (++i < rules->philo_count)
			{
				if (check_death(rules, i))
					return (NULL);
			}
			if (check_all_ate(rules))
				return (NULL);
			start = current;
		}
		usleep(100);
	}
	return (NULL);
}
