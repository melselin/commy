/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:32:11 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/02 22:43:43 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include <stdio.h>
#include "libft.h"
size_t ft_strlen(const char *str)
{
 int  i=0;
 while (str[i] !='\0'){
  i++;
 }
 return (i);
}
/*
int main(void) {
 printf("%i\n", ft_strlen("hello world"));
return (0);
}*/