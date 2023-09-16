
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    int rc = fork();


    if (rc < 0) { // fork failed; exit
	fprintf(stderr, "fork failed\n");
        exit(1);

    }

    else if (rc == 0) { // child (new process)
	printf("_____This is the clild malaka______\n");
        char * const argv[] = {"ls", NULL};
        char * const envp[] = {NULL};

       // execl("/bin/ls", "ls", NULL);
    	 //execle("/bin/ls", "ls", NULL, envp);
	 // execlp("ls", "ls", NULL);



        //execvp("ls", argv);
	execv("/bin/ls", argv);

        //execvpe("ls", argv, envp);
	}

     else { // parent goes down this path (main)
	wait(NULL);
	printf("hello, I am parent\n");
	}

     return 0;
}


/*********************************************
   Your name: karakostasz
   Question 1:Why do
you think there are so many variants of the same basic call?
	- The goal of these calls is to execute files. Despite the
 fact that they are similar to one another, they differ
 in the kinds of documents they require,
 which affects what tasks they are best suited for. in other words,
 each variation has a distinct function, but the can still be used interchangeably.
*********************************************/
