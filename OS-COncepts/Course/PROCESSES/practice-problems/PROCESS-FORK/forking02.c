/**
 * Lets try top open another file using execlp function after forking.
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    pid_t pid;

    pid = fork();

    if(pid == 0)
    {
        printf("\nPID of the Child is %d\n", getpid());
        printf("\nPID of the parent is %d \n", getppid());
        //exec function if success will not return anything and return -1 for failure.
        execlp("/mnt/c/Personal-Projects/OS-COncepts/Course/PROCESSES/practice-problems/exec-cat.out", "./exec-cat.out", NULL);
    }
    else
    {
        wait(NULL);
        printf("\nPID of the parent is %d \n", getpid());
        printf("\nBYE\n");
    }
    return 0;
}
