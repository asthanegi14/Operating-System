#include <stdio.h>
#include<unistd.h>

int main()
{
    fork();
    printf("Linux\n");
    fork();
    printf("Unix\n");
    fork();
    printf("Red Hat\n");

    return 0;
}

