/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:15:58 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 09:58:17 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    while (*str == 32 || (*str >=9 && *str<=13))
        {
            str++;
        }
    if (*str == '-')
    {
        sign *= -1;
    }
    if (*str == '+' || *str == '-')
    {
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result * sign);
}
