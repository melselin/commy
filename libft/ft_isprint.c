/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:15:14 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 10:54:38 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int ft_isprint(int c) {
    return(c >= 32 && c <= 126);
}
/*
int main(void) {
    printf("%d\n", ft_isprint(0));
    printf("%d\n", ft_isprint(127));
    printf("%d\n", ft_isprint(60));
}*/
