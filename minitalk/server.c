#include "minitalk.h"

void handle_signal(int sig, siginfo_t *info, void *context) {
    (void)info;
    (void)context;

    static int bit_count = 0;
    static char character = 0;

    if (sig == SIGUSR1)
        character |= (0 << (7 - bit_count));
    if (sig == SIGUSR2)
        character |= (1 << (7 - bit_count));

    if (++bit_count == 8) {
        write(1, &character, 1);
        bit_count = 0;
        character = 0;
    }
}


int main() {
    struct sigaction action;

    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = handle_signal;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);

    ft_printf("Server PID: %d\n", getpid());
    while (1)
        pause();
    return 0;
}

