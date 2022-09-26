#include <stdio.h>
#include<unistd.h>

int main()
{
    fork();     //calling fork to create a child process
    printf("DemoDemo\n");

    return 0;
}

