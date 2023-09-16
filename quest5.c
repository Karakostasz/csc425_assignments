
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

 else if (rc == 0) { // child 
 // int rc_wait = wait(NULL);
 // printf("hello, I am child (pid:%d)\n",rc_wait, (int) getpid());
 printf("hello, I am child (pid:%d)\n", (int) getpid());
 }

 else { // parent
 // printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",  rc, (int) getpid());
 int rc_wait = wait(NULL);
printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
}

 return 0;
}
/*********************************************
   Your name:karakostasz
    Question 1: The Wait() call, returns the process id for the child that finished
 it process. After using the Wait() call in the child it
 returns -1, giving an error, as the child does not have a child to wait
 for. Wait() works only for parents waiting for their
 child or children to complete a process. 
*********************************************/
