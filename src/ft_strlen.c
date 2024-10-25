/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:32:11 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/24 11:43:23 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include <stdio.h>
int ft_strlen(char *s)
{
 int  i=0;
 while (s[i] !='\0'){
  i++;
 }
 return (i);
}
/*
int main(void) {
 printf("%i\n", ft_strlen("hello world"));
return (0);
}*/