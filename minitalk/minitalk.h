#ifndef MINITALK_H
# define MINITALK_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif
extern char g_message[BUFFER_SIZE];
extern int g_index;

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

// Common utilities
void    send_char(int pid, char c);
void    send_message(int pid, char *message);
void    error_exit(const char *msg);
void signal_handler(int signum);

#endif
