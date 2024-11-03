/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:32:11 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 10:57:27 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include <stdio.h>
#include "libft.h"
size_t ft_strlen(const char *str)
{
 size_t i = 0;
 while (str[i] !='\0'){
  i++;
 }
 return (i);
}
/*
int main(void) {
 printf("%zu\n", ft_strlen("hello world"));
return (0);
}*/