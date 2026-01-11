/**
 * This program demonstrates the use of forking in a Unix-like operating system.
 * It creates a child process using the fork() system call and shows how the
 * parent and child processes can execute concurrently.

 */

 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
 #include <stdio.h>

 int main()
 {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        // This function replaces the child process with the "ls" command, 
        // first parameter is the path to the binary and rest are the arguments to the command.
        // execlp("/bin/ls", "ls", NULL);    
        printf("Hello from the child process! My PID is %d\n", getpid());
    }
    else {
        // Parent process
        // wait makes the parent collect the exit status of the child process
        wait(NULL); // Wait for child process to finish, although not strictly necessary here, since called implicitly by execlp
        printf("Hello from the parent process! My PID is %d and my child's PID is %d\n", getpid(), pid);
    }    

    return 0;
 }
 

 