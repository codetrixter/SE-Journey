#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int x = 10;

void* function(void* args)
{
    int sum = 0;
    int* val = (int*)args;
    sum = x + *val;
    printf("\n Sum = %d", sum);
    printf("\nThread Exiting...");
    pthread_exit(0);
}
int main()
{
    pthread_t tid1, tid2;
    pthread_attr_t attr1, attr2;
    int a = 10, b = 20;

    //Initialize the thread attributes
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    //Creating threads
    pthread_create(&tid1, &attr1, function, &a);
    pthread_create(&tid1, &attr1, function, &b);

    //waiting for threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid1, NULL);

    printf("\n Main thread Exiting...");
    return 0;
}
