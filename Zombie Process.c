#include <stdio.h>
#include<unistd.h>
#include <sys/types.h>

int main()
{
    printf("Astha Negi\t20012596\t16,J\n");
    pid_t pid=fork();
    if(pid>0){
        printf("Parent is sleeping for 15 sec....\n");
        sleep(15);
    }
    else{
        printf("child process become zombie process\n");
        exit(0);
    }

    return 0;
}


