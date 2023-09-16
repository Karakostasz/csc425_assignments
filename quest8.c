#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>
 
int main(int argc, char *argv[])
{
    int fd1[2]; // Used to store two ends of first pipe
    if (pipe(fd1) == -1) {//pipe function
        fprintf(stderr, "Pipe Failed");
        return 1;
    }

    int frk1 = fork();
    if (frk1<0) {
        printf("fork failed\n");
        exit(1);
    }

    else if (frk1 == 0) {
        dup2(fd1[1], 1); // redirect stdout
        printf("MALAKA this is the first child talking\n");
    }

    else {
        int frk2 = fork();
        if (frk2 < 0){ // fork failed; exit
            printf("fork failed\n");
            exit(1);
        }

        else if (frk2 == 0){ // second child
            dup2(fd1[0], STDIN_FILENO); 
            char delivery[300];
          //fgets(delivery,300, file?);
          gets(delivery);
            printf("this is the second child delivering, number 1 said:\n  \"%s\"\n", delivery);
        }

        else {//parent
            wait(NULL);
        }
    }
    return 0;
}
