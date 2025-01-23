/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:06:46 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/01/23 09:06:49 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void send_char(int pid, char c) {
    for (int i = 7; i >= 0; i--) {
        if ((c >> i) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(300); // Sinyallerin çakışmasını önlemek için daha uzun bekleme süresi
    }
}

void send_message(int pid, char *message) {
    while (*message)
        send_char(pid, *message++);
    send_char(pid, '\0'); // Mesajın bittiğini belirtmek için NULL karakter gönder
}

int main(int argc, char **argv) {
    if (argc != 3) {
        ft_printf("Usage: ./client [server_pid] [message]\n");
        return 1;
    }

    int server_pid = ft_atoi(argv[1]);
    if (server_pid <= 0) {
        ft_printf("Invalid PID.\n");
        return 1;
    }

    send_message(server_pid, argv[2]);

    return 0;
}

