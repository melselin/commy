/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_troupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:35:45 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 13:37:43 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int ft_troupper(int c)
{
    const int   ascii_difference = 'a' - 'A';

    if (c >= 'a' && c <= 'z') {
        return c - ascii_difference;
    }

    return c;
}