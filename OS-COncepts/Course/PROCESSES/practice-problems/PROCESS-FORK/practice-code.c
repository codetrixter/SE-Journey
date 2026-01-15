/**
 * Here we try figuring the output of the code snippet.
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

// Code 1
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
int main1()
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

// Code 2
/**
 * This code demonstrates conditional execution based on fork() return value.
 *
 * fork() return values:
 *   - Returns 0 to the CHILD process
 *   - Returns child's PID (positive) to the PARENT process
 *   - Returns -1 on failure
 *
 * Execution flow:
 *   PARENT process:
 *     - fork() returns child's PID (non-zero), so if condition is FALSE
 *     - Skips printf("BAD")
 *     - Prints "HELLO"
 *
 *   CHILD process:
 *     - fork() returns 0, so if condition is TRUE
 *     - Prints "BAD"
 *     - Falls through (no else/return) and also prints "HELLO"
 *
 * Expected Output (order may vary due to process scheduling):
 *   BAD      (from child only)
 *   HELLO    (from child)
 *   HELLO    (from parent)
 *
 * Total: 1 "BAD" + 2 "HELLO" = 3 lines printed
 * Note: The order of output is non-deterministic since both processes
 * run concurrently and the OS scheduler decides execution order.
 */
int main2()
{
        // fork() creates a child process
        // Returns 0 to child, child's PID to parent
        if (fork() == 0) // This block executes ONLY in the child process
                printf("\nBAD\n");

        // Both parent and child execute this line
        // (child falls through after printing BAD, parent skips the if block)
        printf("\nHELLO\n");

        return 0;
}

// Code 3
/**
 * This code demonstrates fork() combined with exec() system call.
 *
 * Key concept: execlp() REPLACES the current process image with a new program.
 * If exec succeeds, the code after it NEVER executes (process is replaced).
 * If exec fails, execution continues normally.
 *
 * Execution flow:
 *   PARENT process (fork() != 0 is TRUE):
 *     - Calls execlp("/bin/rm", "rm", "abc.txt", NULL)
 *     - If abc.txt exists and rm succeeds:
 *         * Parent process is REPLACED by /bin/rm
 *         * "AFTER EXEC" is NEVER printed (process replaced)
 *         * "THE END" is NEVER printed by parent (process replaced)
 *     - If exec fails (e.g., file doesn't exist or permission denied):
 *         * "AFTER EXEC" would print
 *         * "THE END" would print
 *
 *   CHILD process (fork() != 0 is FALSE, i.e., fork() == 0):
 *     - Sleeps for 3 seconds
 *     - Prints "BYE"
 *     - Prints "THE END"
 *
 * Expected Output (assuming exec succeeds):
 *   (3 second delay)
 *   BYE        (from child)
 *   THE END    (from child only - parent was replaced by rm)
 *
 * Note: "AFTER EXEC" will NEVER print if execlp() succeeds because
 * the entire parent process memory is replaced by the rm program.
 */
int main3()
{
        // fork() != 0 is TRUE in parent (returns child PID), FALSE in child (returns 0)
        if (fork() != 0)
        {
                // PARENT PROCESS BLOCK
                // execlp replaces current process with /bin/rm program
                // Arguments: path, arg0 (program name), arg1 (file to delete), NULL terminator
                execlp("/bin/rm", "rm", "abc.txt", NULL);

                // This line ONLY executes if execlp() FAILS
                // On success, the process is completely replaced - this code is gone
                printf("\nAFTER EXEC\n");
        }

        else
        {
                // CHILD PROCESS BLOCK
                sleep(3); // Wait 3 seconds

                printf("\nBYE\n");
        }

        // Only child reaches here (parent was replaced by exec)
        // Unless exec failed, then parent also prints this
        printf("\nTHE END\n");

        return 0;
}

// Code 4
/**
 * This code demonstrates fork() combined with wait() system call.
 *
 * Key concept: wait(NULL) blocks the calling process until one of its
 * child processes terminates. It returns the PID of the terminated child,
 * or -1 if there are no children to wait for.
 *
 * Execution flow:
 *   PARENT process (fork() != 0 is TRUE):
 *     - Calls wait(NULL) which BLOCKS until child terminates
 *     - After child exits, wait() returns the child's PID
 *     - Prints "PARENT:: <child_pid>"
 *
 *   CHILD process (fork() != 0 is FALSE):
 *     - Prints "CHILD PID:: <its_own_pid>"
 *     - Sleeps for 3 seconds
 *     - Calls wait(NULL) - but child has NO children of its own!
 *     - wait() returns -1 (error: no child processes)
 *     - Prints "Child:: -1"
 *
 * Expected Output (order is DETERMINISTIC here due to wait()):
 *   CHILD PID:: <child_pid>    (child prints first)
 *   (3 second delay)
 *   Child:: -1                  (child's wait returns -1, no children)
 *   PARENT:: <child_pid>        (parent's wait returns after child exits)
 *
 * Note: The parent is BLOCKED by wait() until child terminates,
 * so parent's print always comes AFTER all child's prints.
 */
int main4()
{
        // fork() != 0 is TRUE in parent, FALSE in child
        if (fork() != 0)
        {
                // PARENT PROCESS BLOCK
                // wait(NULL) blocks until child terminates
                // Returns the PID of the terminated child process
                printf("\nPARENT:: %d\n", wait(NULL));
        }

        else
        {
                // CHILD PROCESS BLOCK
                // getpid() returns this process's own PID
                printf("\nCHILD PID:: %d\n", getpid());

                sleep(3); // Sleep for 3 seconds

                // Child has no children, so wait() returns -1 (error)
                printf("\nChild:: %d\n", wait(NULL));
        }

        return 0;
}

// Code 5

int main()
{

        int x = 10;

        if (fork() != 0)
        {
                
                x = x + 10;
                // this will get printed fiest since child is sleeping for 3 seconds : 20
                printf("\nPARENT:: %d\n", x);
        }

        else
        {

                sleep(3);
                // This will get printed last after 3 seconds :10
                printf("\nChild:: %d\n", x);
        }

        return 0;
}
