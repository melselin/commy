/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:15:14 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/24 11:30:30 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include <stdio.h>
int ft_isprint(int c) {
    if(c >= 32 && c <= 126)
    {
        return (1);
    }
    else return (0);
}
/*
int main(void) {
    printf("%d\n", ft_isprint(0));
    printf("%d\n", ft_isprint(127));
    printf("%d\n", ft_isprint(60));
}*/
