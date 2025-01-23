/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:06:55 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/01/23 09:06:57 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

char g_message[BUFFER_SIZE];
int g_index = 0;
char g_current_char = 0;
int g_bit_index = 0;

void signal_handler(int signum) {
    if (signum == SIGUSR1)
        g_current_char |= (1 << (7 - g_bit_index)); // 1 ise biti ayarla
    g_bit_index++;

    if (g_bit_index == 8) { // 1 karakter tamamlandığında
        g_message[g_index++] = g_current_char;
        if (g_index >= BUFFER_SIZE - 1) { // Buffer taşmasını önle
            write(1, "Buffer overflow detected\n", 25);
            g_index = 0;
        }

        if (g_current_char == '\0') { // Mesajın sonuna geldiğinde
            write(1, g_message, g_index - 1); // Mesajı yazdır
            write(1, "\n", 1);
            g_index = 0; // Mesajı sıfırla
        }
        g_current_char = 0;
        g_bit_index = 0;
    }
}

int main(void) {
    struct sigaction sa;

    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    ft_printf("Server PID: %d\n", getpid());

    while (1)
        pause(); // Sinyal bekle

    return 0;
}
