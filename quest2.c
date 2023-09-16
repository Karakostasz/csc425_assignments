
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>




 int main(){

        int thefile = open("basano.txt", O_CREAT|O_WRONLY|O_RDWR, S_IRWXU);
        int rc = fork();


        if (rc < 0) { // fork failed; exit
                 fprintf(stderr, "fork failed\n");
                 exit(1);

        } else if (rc == 0) { // child (new process)
                printf("hello, I am child\n");
                const char * child_message = "Its the child malaka\n";
                write(thefile, child_message, strlen(child_message));
                exit(1);
                }

        else { // parent goes down this path (main)
                wait(NULL);
                printf("hello, I am parent\n");
                const char * parent_message = "yoo parent here writing\n";
                write(thefile, parent_message, strlen(parent_message));

        }

         lseek(thefile, 0, SEEK_SET);
         printf("we good?");
         char * whatin = malloc(sizeof(whatin));
         read(thefile, buffer, sizeof(whatin));

         printf("Content of file: \n%s", whatin);

        close(thefile);
        return 0;
        }




/*********************************************
   Your name:karakostasz
   Question 1:What happens when they are writing to the file concurrently, i.e.,
 at the same time? 
	-The file descriptor opened and is accessible to both the child and the parent. they can write to the file, but the sequence in which they do so can b
	e unpredictable if the wait() system call is not used.
*********************************************/
