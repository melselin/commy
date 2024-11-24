/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:42:15 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/21 09:42:25 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	put_nbr_base(unsigned long nb, char *base)
{
	int		len;
	int		base_len;

	len = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nb >= (unsigned long)base_len)
		len += put_nbr_base(nb / base_len, base);
	ft_putchar(base[nb % base_len]);
	len++;
	return (len);
}

int	ft_putptr(void *p)
{
	unsigned long	ptr;
	int				len;

	ptr = (unsigned long)p;
	len = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	len += put_nbr_base(ptr, "0123456789abcdef");
	return (len);
}
