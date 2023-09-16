#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

 int main(int argc, char *argv[]) {
 printf("hello world (pid:%d)\n", (int) getpid());
 int rc = fork();

 if (rc < 0) { // fork failed; exit
 fprintf(stderr, "fork failed\n");
 exit(1);
 }

 else if (rc == 0) { // child (new process)
 close(STDOUT_FILENO);
 printf("hello, I am child \n");
 }

else { // parent goes down this path (main)

 wait(NULL);
 printf("hello, I am parent of\n");

 }

 return 0;
}

/*********************************************
   Your name:karakostasz
   Question 7:I did not receive any kind of error using printf(), but nothing is outputted to the screen if we shut the stdout file descriptor.
*********************************************/
