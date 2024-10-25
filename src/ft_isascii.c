/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:24:26 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/24 11:30:15 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include <stdio.h>
int ft_isascii(int c) {
    if(c>=0 && c<=127) return (1);
    else return (0);
}
/*
int main(void) {
    printf("%d\n", ft_isascii(0));
    printf("%d\n", ft_isascii(127));
    printf("%d\n", ft_isascii(129));
    printf("%d\n", ft_isascii(22));
}*/