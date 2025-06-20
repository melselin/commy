/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:00:00 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/05/04 00:00:00 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void	precise_usleep(long long time_ms)
{
	long long	start;
	long long	elapsed;

	start = timestamp();
	elapsed = timestamp() - start;
	while (!(elapsed >= time_ms))
	{
		if (time_ms - elapsed > 1000)
			usleep(500);
		else
			usleep((time_ms - elapsed) * 500);
		elapsed = timestamp() - start;
	}
}
