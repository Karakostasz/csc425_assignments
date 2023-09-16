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
 printf("hello, I am child %d\n", (int) getpid());
 }

//pid_t waitpid(pid_t pid, int *statusPtr, int options);

else { // parent goes down this path (main)
 int status;
 waitpid(rc, &status, 0);
 printf("hello, I am parent of %d\n", (int) getpid());
 }

 return 0;
}
/*********************************************
   Your name: karakostasz
   Question 6:When we wish to wait for a single child process rather than waiting for all child processes to terminate once their process is complete, we utilize the waitpid() call that allows for more control in our actions. I further saw that waitpid () takes a number of arguments that could potentially offer even more control and the ability to do even more specific work.
*********************************************/
