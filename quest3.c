#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

printf("i'm working\n");
    int pipe_fd[2];

    if (pipe(pipe_fd) == -1) {
        printf("Pipe creation failed\n");
        exit(1);
    }

    int rc = fork();

    if (rc < 0) { // fork failed; exit
        printf("Fork failed\n");
        exit(1);
    }
    else if (rc == 0) { // child process
        close(pipe_fd[0]); // Close the read end of the pipe

        printf("Child: hello\n");
        write(pipe_fd[1], "c", 1);
        close(pipe_fd[1]); // Close the write end of the pipe in the child
    }
    else { // parent process

        close(pipe_fd[1]); // Close the write end of the pipe in the parent
        char signal;
        read(pipe_fd[0], &signal, 1);
        printf("Parent: goodbye\n");
        close(pipe_fd[0]); // Close the read end of the pipe in the parent
    }

    return 0;
}
