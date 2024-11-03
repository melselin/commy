/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:36:42 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 13:39:15 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int	ft_tolower(int c) {
    const int   ascii_difference = 'a' - 'A';

    if (c >= 'A' && c <= 'Z') {
        return c + ascii_difference;
    }

    return c;
}