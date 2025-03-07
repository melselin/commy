/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:43:54 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/21 09:44:00 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	if (n >= 10)
		return (ft_putunbr(n / 10) + ft_putchar(n % 10 + '0'));
	return (ft_putchar(n + '0'));
}
