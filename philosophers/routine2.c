/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:52:29 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/05/03 23:52:47 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		usleep(15000);
	while (1)
	{
		pthread_mutex_lock(&philo->rules->meal_check);
		if (philo->rules->died || philo->rules->all_ate)
		{
			pthread_mutex_unlock(&philo->rules->meal_check);
			break ;
		}
		pthread_mutex_unlock(&philo->rules->meal_check);
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

int	handle_single_philo(t_rules *rules)
{
	long long	current_time;

	current_time = timestamp() - rules->start_time;
	printf(MSG_FORK, current_time, 1);
	printf(MSG_FORK, current_time, 1);
	usleep(rules->time_to_die * 1000);
	current_time = timestamp() - rules->start_time;
	printf(MSG_DEATH, current_time, 1);
	return (0);
}
