#include <los/error.h>
#include <los/signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3 && argc != 4) {
        fprintf(stderr, "USAGE: %s [SESSION] PROCESS SIGNAL\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int result;
    if (argc == 3) {
        isize pid = atol(argv[1]);
        u8 signal = atoi(argv[2]) & 0xFF;

        result = raise_process(pid, signal);
    } else {
        isize sid = atol(argv[1]);
        isize pid = atol(argv[2]);
        u8 signal = atoi(argv[3]) & 0xFF;

        result = raise_session(sid, pid, signal);
    }

    if (result != EOK) {
        fprintf(stderr, "Error - %s\n", strerror(result));
        exit(EXIT_FAILURE);
    }

    return 0;
}