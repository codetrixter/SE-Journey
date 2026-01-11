#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    execlp("/bin/cat", "cat", "wassup.txt", NULL);
    return 0;
}
