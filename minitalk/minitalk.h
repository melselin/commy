#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include "libft/libft.h"

// Fonksiyon prototipleri

// server.c için
void handle_signal(int sig, siginfo_t *info, void *context);
void    print_pid(void);

// client.c için
void	send_char(int pid, char c);

#endif

