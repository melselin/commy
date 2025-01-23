#include "minitalk.h"

void send_char(int pid, char c) {
    for (int i = 7; i >= 0; i--) {
        if (c & (1 << i))
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(300);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        write(1, "Usage: ./client [PID] [Message]\n", 32);
        return 1;
    }

    int pid = ft_atoi(argv[1]);
    char *message = argv[2];

    for (int i = 0; message[i]; i++) {
        send_char(pid, message[i]);
    }

    return 0;
}

