/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:52:14 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/05/03 23:53:03 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules		rules;
	pthread_t	monitor_thread;
	int			i;

	if (!is_valid_input(argc, argv))
		return (error_exit("Error: Invalid arguments"));
	if (init_all(&rules, argv))
		return (1);
	if (rules.philo_count == 1)
		return (handle_single_philo(&rules));
	if (pthread_create(&monitor_thread, NULL, monitor, &rules))
		return (error_exit("Error: Monitor thread creation failed"));
	i = -1;
	while (++i < rules.philo_count)
		if (pthread_create(&rules.philos[i].thread_id, NULL, routine,
				&rules.philos[i]))
			return (error_exit("Error: Philosopher thread creation failed"));
	pthread_join(monitor_thread, NULL);
	i = -1;
	while (++i < rules.philo_count)
		pthread_join(rules.philos[i].thread_id, NULL);
	cleanup(&rules);
	return (0);
}
