/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:52:29 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/05/03 23:52:47 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->forks[philo->left_fork]);
	print_action(philo->rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->rules->forks[philo->right_fork]);
	print_action(philo->rules, philo->id, "has taken a fork");
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->meal_check);
	philo->last_meal = timestamp();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->rules->meal_check);
	pthread_mutex_lock(&philo->rules->writing);
	if (!philo->rules->died && !philo->rules->all_ate)
		printf(MSG_EAT, timestamp() - philo->rules->start_time, philo->id);
	pthread_mutex_unlock(&philo->rules->writing);
	precise_usleep(philo->rules->time_to_eat);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->rules->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->rules->forks[philo->right_fork]);
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo->rules, philo->id, "is sleeping");
	precise_usleep(philo->rules->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_action(philo->rules, philo->id, "is thinking");
	usleep(100);
}
