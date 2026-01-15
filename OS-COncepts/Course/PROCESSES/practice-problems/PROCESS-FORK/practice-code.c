/**
 * Here we try figuring the output of the code snippet.
 */

 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
 #include <stdio.h>

//Code 1
/**
 * This code demonstrates process creation using fork().
 * 
 * Each fork() call creates a new child process, effectively doubling
 * the total number of processes. Both parent and child continue
 * execution from the point after fork().
 * 
 * Process count progression:
 *   - Start:           1 process
 *   - After 1st fork: 2 processes  (2^1)
 *   - After 2nd fork: 4 processes  (2^2)
 *   - After 3rd fork: 8 processes  (2^3)
 *   - After 4th fork: 16 processes (2^4)
 * 
 * Total processes created = 2^n where n = number of fork() calls
 * In this case: 2^4 = 16 processes
 * 
 * Each of the 16 processes will print "HELLO" along with its unique PID.
 */
int main()
{
    // Fork #1: 1 process becomes 2 (original parent + 1 child)
    fork();

    // Fork #2: 2 processes become 4 (each of the 2 processes creates a child)
    fork();

    // Fork #3: 4 processes become 8
    fork();

    // Fork #4: 8 processes become 16
    fork();

    // All 16 processes execute this line, each printing its own unique PID
    // getpid() returns the process ID of the calling process
    printf("\nHELLO:: %d\n", getpid());

    return 0;

}

//Code 2

int main2()
{

    if(fork() == 0)

            printf("\nBAD\n");

    printf("\nHELLO\n");

    return 0;

}

//Code 3

int main3()
{

    if(fork() != 0)
    {

            execlp("/bin/rm", "rm", "abc.txt", NULL);

            printf("\nAFTER EXEC\n");

    }

    else
    {

            sleep(3);

            printf("\nBYE\n");

    }

    printf("\nTHE END\n");

    return 0;

}

//Code 4

int main4()
{

    if(fork() != 0)
    {

            printf("\nPARENT:: %d\n", wait(NULL));

    }

    else
    {

            printf("\nCHILD PID:: %d\n", getpid());

            sleep(3);

            printf("\nChild:: %d\n", wait(NULL));

    }

    return 0;

}

//Code 5

int main5()
{

    int x = 10;

    if(fork() != 0)
    {

            x = x + 10;

            printf("\nPARENT:: %d\n", x);

    }

    else
    {

            sleep(3);

            printf("\nChild:: %d\n", x);

    }

    return 0;

}

