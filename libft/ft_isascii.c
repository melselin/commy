/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meriza <meriza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:31:04 by meriza            #+#    #+#             */
/*   Updated: 2024/11/03 10:53:44 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isascii(int c) {
    return(c>=0 && c<=127);
}
/*
int main(void) {
    printf("%d\n", ft_isascii(0));
    printf("%d\n", ft_isascii(127));
    printf("%d\n", ft_isascii(129));
    printf("%d\n", ft_isascii(22));
}*/