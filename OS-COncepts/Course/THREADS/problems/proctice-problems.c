/**
 * Explore and analyse the following code snippets and their behaviour...
 */

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

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

void * runner1(void *param)
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
}

// Code 3---------------------------------------------------------------

/* void * runner1(void *param)
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

/* void * runner1(void *param)
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
    {
        if (i % 2 == 0)
            pthread_create(&tid[i], &attr, runner1, &arr[i]);

        else
        {
            int x = arr[i] - 1000;

            pthread_create(&tid[i], &attr, runner1, &x);
        }
    }

    for (int i = 0; i < 20; i++)
        pthread_join(tid[i], NULL);

    printf("\nMain Thread Done, PID = %d\n", getpid());
} */

// Code 5---------------------------------------------------------------

/* unsigned long s = 0;
unsigned long m = 1;

void *runner1(void *param)
{
    unsigned long p;

    p = atoi(param);

    for (unsigned long i = 1; i <= p; i++)
        s += i;

    pthread_exit(0);
}

void *runner2(void *param)
{
    unsigned long x;

    x = atoi(param);

    for (unsigned long i = 1; i <= x; i++)
        m *= i;

    pthread_exit(0);
}

int main(int argc, char *argv[])

{
    pthread_t tid1, tid2;

    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid1, &attr, runner1, argv[1]);

    pthread_create(&tid2, &attr, runner2, argv[2]);

    pthread_join(tid1, NULL);

    pthread_join(tid2, NULL);

    printf("\n sum = %lu\n", s);

    printf("\n product = %lu\n", m);

    printf("\nMain Thread Done, PID = %d\n", getpid());
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

    pthread_cancel(tid);

    printf("\nsum = %lu\n", sum);

    printf("\nMain Thread Done, PID = %d\n", getpid());
} */

// Code 8---------------------------------------------------------------

/* void * runner1(void *param)
{

    pthread_t td;

    td = (pthread_t)(param);

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

    printf("\n1:: %d\n", pthread_equal(tid1, tid2));

    tid3 = pthread_self();

    printf("\n2:: %d\n", pthread_equal(tid3, pthread_self()));

    pthread_join(tid1, NULL);

    pthread_join(tid2, NULL);

    printf("\nMain Thread Done, PID = %d\n", getpid());
} */