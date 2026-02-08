/**
 * Explore and analyse the following code snippets and their behaviour...
 */

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> //atoi

// Code 1---------------------------------------------------------------
// Demonstrates passing thread IDs to thread functions
// WARNING: This code has a race condition - passing address of tid1/tid2
// The thread reads the address after it's been written, which may have changed

/* void * runner1(void *param)
{
    pthread_t td;
    // Cast the void pointer back to pthread_t
    // Note: param points to tid1 or tid2 in main(), which might change before this reads it
    td = (pthread_t)(param);

    // Print the thread ID (as unsigned long)
    printf("\n%lu\n", td);
    
    // Terminate the thread and return NULL
    pthread_exit(0);
}

int main()
{
    // Declare two thread identifiers
    pthread_t tid1, tid2;
    
    // Declare thread attributes structure
    pthread_attr_t attr;

    // Initialize thread attributes to default values
    pthread_attr_init(&attr);

    // Create first thread: executes runner1, passing address of tid1 as parameter
    // RACE CONDITION: tid1 might not be fully written before runner1 reads it
    pthread_create(&tid1, &attr, runner1, &tid1);
    
    // Create second thread: executes runner1, passing address of tid2 as parameter
    // RACE CONDITION: tid2 might not be fully written before runner1 reads it
    pthread_create(&tid2, &attr, runner1, &tid2);

    // Wait for first thread to complete before continuing
    pthread_join(tid1, NULL);
    
    // Wait for second thread to complete before continuing
    pthread_join(tid2, NULL);

    // Print main thread's process ID after all threads complete
    printf("\nMain Thread Done, PID = %d\n", getpid());
} */

// Code 2---------------------------------------------------------------
// Demonstrates the same race condition as Code 1, but with 20 threads
// BUG: This code has MULTIPLE serious issues:
// 1. Race condition - passing &tid[i] before pthread_create writes to it
// 2. Type confusion - casting pthread_t* (pointer) directly to pthread_t (value)
// 3. May print < 20 thread IDs due to race conditions and undefined behavior

/* void * runner1(void *param)
{
    pthread_t td;

    // WRONG: param is a pthread_t* (pointer), but we're casting it to pthread_t (value)
    // This should be: td = *(pthread_t*)(param); to dereference the pointer
    // Currently reads the memory ADDRESS as if it were a thread ID!
    td = (pthread_t)(param);
    
    // Multiple threads calling printf simultaneously can interleave output
    printf("\n%lu\n", td);

    pthread_exit(0);
}

int main()
{
    // Array to hold 20 thread identifiers
    pthread_t tid[20];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // Create 20 threads rapidly in a loop
    // RACE CONDITION: Each thread receives &tid[i], but tid[i] may not be
    // fully initialized by pthread_create before the thread reads it
    for (int i = 0; i < 20; i++)
        pthread_create(&tid[i], &attr, runner1, &tid[i]);

    // Wait for all 20 threads to complete
    for (int i = 0; i < 20; i++)
        pthread_join(tid[i], NULL);

    printf("\nMain Thread Done, PID = %d\n", getpid());
} */

// Code 3---------------------------------------------------------------

/* void* runner1(void *param)
{
    int *p;

    p = (int *)(param);

    printf("\n%d\n", *p);

    pthread_exit(0);
}

int main()

{
    pthread_t tid[20];

    int arr[20];

    for (int i = 0; i < 20; i++)
        arr[i] = (i + 1) * 10;

    pthread_attr_t attr;

    pthread_attr_init(&attr);

    for (int i = 0; i < 20; i++)
        pthread_create(&tid[i], &attr, runner1, &arr[i]);

    for (int i = 0; i < 20; i++)
        pthread_join(tid[i], NULL);

    printf("\nMain Thread Done, PID = %d\n", getpid());
} */

// Code 4---------------------------------------------------------------
// Demonstrates CRITICAL BUG: Passing address of local variable to thread
// Even-indexed threads: Work correctly (pass address from arr[])
// Odd-indexed threads: UNDEFINED BEHAVIOR (pass address of local variable x)
// 
// Why it "seems" to work despite the bug:
// 1. Stack memory persistence - x's memory isn't immediately overwritten
// 2. pthread_create() overhead - thread might read x before stack corruption
// 3. Stack reuse - compiler might use same stack location for x each iteration
// 4. Lucky timing - threads read values before the loop overwrites them
//
// This is a SEVERE BUG that will eventually cause:
// - Garbage values printed
// - Values from wrong iterations
// - Potential segmentation faults
// - Heisenbug behavior (changes with optimization levels, system load, etc.)

/* void* runner1(void *param)
{
    int *p;

    // Cast the void pointer back to int pointer
    p = (int *)(param);
    
    // Dereference and print the integer value
    // For odd threads: This reads from a DANGLING POINTER (undefined behavior!)
    printf("\n%d\n", *p);

    pthread_exit(0);
}

int main()

{
    pthread_t tid[20];
    pthread_attr_t attr;

    // Initialize array with values: 10, 20, 30, ..., 200
    int arr[20];
    for (int i = 0; i < 20; i++)
        arr[i] = (i + 1) * 10;

    pthread_attr_init(&attr);

    for (int i = 0; i < 20; i++)
    {
        // Even-indexed threads (i = 0, 2, 4, ..., 18)
        // SAFE: Pass address of arr[i], which remains valid throughout execution
        // Should print: 10, 30, 50, 70, 90, 110, 130, 150, 170, 190
        if (i % 2 == 0)
            pthread_create(&tid[i], &attr, runner1, &arr[i]);

        // Odd-indexed threads (i = 1, 3, 5, ..., 19)
        // CRITICAL BUG: Pass address of local variable x
        else
        {
            // x is a LOCAL VARIABLE that goes out of scope at end of this block
            int x = arr[i] - 1000;
            
            // DANGER: &x is passed to thread, but x is destroyed when block exits!
            // The thread will receive a DANGLING POINTER
            // Should print: -980, -970, -960, ..., -810 (if it worked correctly)
            // May print: garbage, wrong values, or crash
            pthread_create(&tid[i], &attr, runner1, &x);
            
            // x is DESTROYED here, but thread might not have read it yet!
        }
    }

    // Wait for all 20 threads to complete
    // The pthread_join ensures main doesn't exit before threads finish
    for (int i = 0; i < 20; i++)
        pthread_join(tid[i], NULL);

    printf("\nMain Thread Done, PID = %d\n", getpid());
} */

// Code 5---------------------------------------------------------------
// Demonstrates: Command-line argument passing to threads AND DATA RACE on global variables
// 
// USAGE: ./program <number1> <number2>
// Example: ./program 10 5
//   - argv[1] = "10" -> runner1 calculates sum 1+2+3+...+10 = 55
//   - argv[2] = "5"  -> runner2 calculates product 1*2*3*4*5 = 120
//
// RACE CONDITIONS:
// 1. SAFE: argv[] pointers remain valid - passed as string pointers (char*)
// 2. DATA RACE on global variable 's': 
//    - runner1 performs multiple read-modify-write operations (s += i)
//    - main thread reads 's' after join (safe due to happens-before relationship)
// 3. DATA RACE on global variable 'm':
//    - runner2 performs multiple read-modify-write operations (m *= i)
//    - main thread reads 'm' after join (safe due to happens-before relationship)
//
// WHY NO CRASH (usually):
// - Each thread modifies DIFFERENT global variables (s vs m) - no conflict
// - pthread_join() creates memory barrier - main sees final values
// - If multiple threads modified SAME variable, we'd see lost updates
//
// MISSING: Error checking for argc (will crash if no arguments provided!)

/* unsigned long s = 0;  // Global variable - shared memory, modified by runner1
unsigned long m = 1;  // Global variable - shared memory, modified by runner2

void *runner1(void *param)
{
    unsigned long p;

    // param is argv[1] - a char* string from command line
    // atoi converts string to integer (e.g., "10" -> 10)
    p = atoi((char *)param);
    
    // Calculate sum: 1 + 2 + 3 + ... + p
    // Each 's += i' is a DATA RACE if multiple threads access 's'
    // Safe here because only runner1 modifies 's'
    for (unsigned long i = 1; i <= p; i++)
        s += i;

    pthread_exit(0);
}

void *runner2(void *param)
{
    unsigned long x;

    // param is argv[2] - a char* string from command line
    // atoi converts string to integer (e.g., "5" -> 5)
    x = atoi((char *)param);
    
    // Calculate factorial: 1 * 2 * 3 * ... * x
    // Each 'm *= i' is a DATA RACE if multiple threads access 'm'
    // Safe here because only runner2 modifies 'm'
    for (unsigned long i = 1; i <= x; i++)
        m *= i;

    pthread_exit(0);
}

int main(int argc, char *argv[])

{
    pthread_t tid1, tid2;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    // MISSING ERROR CHECK: Should verify argc >= 3 before accessing argv[1] and argv[2]
    // If user doesn't provide arguments, this will crash with segmentation fault
    
    // Create thread 1: Calculate sum of numbers from 1 to argv[1]
    // Passing argv[1] (a char* pointer) directly - SAFE because argv persists
    pthread_create(&tid1, &attr, runner1, argv[1]);
    
    // Create thread 2: Calculate factorial of argv[2]
    // Passing argv[2] (a char* pointer) directly - SAFE because argv persists
    pthread_create(&tid2, &attr, runner2, argv[2]);

    // Wait for both threads to complete
    // pthread_join creates a happens-before relationship:
    // All writes by tid1/tid2 are visible to main after join returns
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // Safe to read 's' and 'm' here - threads have finished modifying them
    printf("\n sum = %lu\n", s);
    printf("\n product = %lu\n", m);
    printf("\nMain Thread Done, PID = %d\n", getpid());

    return 0;
} */

// Code 6---------------------------------------------------------------

/* unsigned long sum = 0;

void *runner1(void *param)
{
    for (unsigned long i = 0; i < 1000000; i++)
        sum += i;

    pthread_exit(0);
}

int main()

{
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner1, NULL);

    // Since main thread is not waiting for the child thread hence this prints 0
    printf("\nsum = %lu\n", sum);
    printf("\nMain Thread Done, PID = %d\n", getpid());
} */

// Code 7---------------------------------------------------------------

/* unsigned long sum = 0;

void *runner1(void *param)
{
    for (unsigned long i = 0; i < 1000000; i++)
        sum += i;

    pthread_exit(0);
}

int main()

{
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner1, NULL);

    // Since the the child thread is destroyed immidiately after creation, hence the sum value printed will be either
    // 0 or some small value.
    pthread_cancel(tid);

    printf("\nsum = %lu\n", sum);
    printf("\nMain Thread Done, PID = %d\n", getpid());
} */

// Code 8---------------------------------------------------------------

void * runner1(void *param)
{

    pthread_t td;

    td = (pthread_t)(param);
    // this can be printed at random order.
    printf("\n%lu\n", td);

    pthread_exit(0);
}

int main()

{
    pthread_t tid1, tid2, tid3;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&tid1, &attr, runner1, &tid1);
    pthread_create(&tid2, &attr, runner1, &tid2);

    // this will return false since both threads are diff.
    printf("\n1:: %d\n", pthread_equal(tid1, tid2));

    tid3 = pthread_self();

    // this will print true, since both are same threads.
    printf("\n2:: %d\n", pthread_equal(tid3, pthread_self()));

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("\nMain Thread Done, PID = %d\n", getpid());
}