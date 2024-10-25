/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:27:47 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/24 11:54:28 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include <stdio.h>
#include "libft.h"
int	ft_isdigit(int c)
{
    if(c >= '0' && c <= '9')
    {
        return (1);
    }
    else return (0);
}
/*
int main() {
    printf("%d\n", ft_isdigit('a'));
    printf("%d\n", ft_isdigit('4'));
}*/