#include <stdio.h>
#include<unistd.h>

int main()
{
    printf("Astha Negi\t20012596\t16,J\n");
    pid_t pid=fork();
    
    if(pid>0){
        printf("parent process with id = %d with child id = %d\n",getppid(),getpid());
    }
    else if(pid==0){
        sleep(9);
        printf("child process of id = %d with parent id = %d\n",getpid(),getppid());
    }
    return 0;
}
