# csc425_assignments
karakosta zach, karakostaz
csc 425 - operating systems

/*********************************************
Question 1:  What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x?
        - The variable value in the child process is equal to the value that I initially set, 100.
        - The parent and child processes each keep a copy of the variables, and the processes cannot overlap and mess with each other address space.

Question 2:What happens when they are writing to the file concurrently, i.e., at the same time?
        -The file descriptor opened and is accessible to both the child and the parent. they can we unpredictable if the wait() system call is not used.

Question 3: No question, see code quest3.c

Question 4: Why do you think there are so many variants of the same basic call?
        - The goal of these calls is to execute files. Despite the fact that they are similar to one another, they differ in the kinds of documents they require, which affects what tasks they are best suited for. in other words, each variation has a distinct function, but the can still be used interchangeably.

Question 5: The Wait() call, returns the process id for the child that finished it’s process. After using the Wait() call in the child it returns -1, giving an error, as the child does not have a child to wait for. Wait() works only for parents waiting for their child or children to complete a process.

Question 6: When we wish to wait for a single child process rather than waiting for all child processes to terminate once their process is complete, we utilize the waitpid() call that allows for more control in our actions. I further saw that waitpid () takes a number of arguments that could potentially offer even more control and the ability to do even more specific work.

Question 7:I did not receive any kind of error using printf(), but nothing is outputted to the screen if we shut the stdout file descriptor.

Question 8: no question, see code
*********************************************/
