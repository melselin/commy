/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:40:42 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/21 09:40:50 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_nbr_rec(int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
		len += ft_nbr_rec(nb / 10);
	ft_putchar((nb % 10) + '0');
	len++;
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putstr("-2147483648");
		return (len);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		len++;
	}
	len += ft_nbr_rec(n);
	return (len);
}
