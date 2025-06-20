/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:52:32 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/05/03 23:52:41 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_rules *rules, int id, char *str)
{
	long long	time;

	pthread_mutex_lock(&rules->writing);
	if (!rules->died && !rules->all_ate)
	{
		time = timestamp() - rules->start_time;
		if (ft_strcmp(str, "died") == 0)
			printf(MSG_DEATH, time, id);
		else if (ft_strcmp(str, "is eating") == 0)
			printf(MSG_EAT, time, id);
		else if (ft_strcmp(str, "is sleeping") == 0)
			printf(MSG_SLEEP, time, id);
		else if (ft_strcmp(str, "is thinking") == 0)
			printf(MSG_THINK, time, id);
		else
			printf(MSG_FORK, time, id);
	}
	pthread_mutex_unlock(&rules->writing);
}

int	error_exit(char *str)
{
	printf("%s\n", str);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

bool	is_valid_input(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
		return (false);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (false);
			j++;
		}
		if (ft_atoi(argv[i]) <= 0)
			return (false);
		i++;
	}
	return (true);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (*p1 && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}
