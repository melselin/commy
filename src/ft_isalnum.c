/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:31:07 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/31 09:36:33 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
int	ft_isalnum(int c) {
    return ft_isalpha(c) || ft_isdigit(c);
}

    int main() {
    printf("%d\n", ft_isalnum('a'));
    return (0);

}