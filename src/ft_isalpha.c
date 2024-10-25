/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:10:17 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/24 11:54:14 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include <stdio.h>
#include "libft.h"
int ft_isalpha(int c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return (1);
    }
    else return (0);
}
/*
int main() {
    printf("%i\n",ft_isalpha('d'));
    return (0);
}*/