
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int z;
	z=100;

	printf("hello world\n");
	int rc = fork();

	if (rc < 0)
	 { // fork failed; exit
		 fprintf(stderr, "fork failed\n");
		 exit(1);
	 }

	 else if (rc == 0)
	 { // child (new process)
		printf("hello, I am child\n");
		printf(" z = %d\n", z);
		z = 500;
		printf(" z = %d\n", z);
	}

	else
	 { // parent goes down this path (main)
		wait(NULL);
		printf("hello, I am parent\n");
		printf(" z = %d\n", z);
		z = 300;
		printf(" z = %d\n", z);

 	}

	return 0;
	}

/*********************************************
   Your name:karakostasz
   Question 1: What value is the variable in the child process?
	- the variable value in the child process is equel to the value that
          I initaily set, 100.

   Question 2: What happens to the variable when both the child and parent change
the value of x?
	- The parent and child processes each keep a copy of the variables, and
	 the processes cannot overlap and mess with each other adress space.
*********************************************/
