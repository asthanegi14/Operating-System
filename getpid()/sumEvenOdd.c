#include <stdio.h>
#include<unistd.h>
int main(){
    int a[10] ={1,40,2,5,10,5,9,6,4,30};
    int Pid = fork();
    int evenSum=0, oddSum=0;
    
    if(Pid==0){
        for(int i=0;i<10;i++){
            if(a[i]%2!=0){
                oddSum+=a[i];
            }
        }
    printf("odd sum = %d of pid = %d\n",oddSum,getpid());
    }
    else{
        for(int i=0;i<10;i++){
            if(a[i]%2==0){
                evenSum+=a[i];
            }
        }
    printf("even sum = %d of pid = %d\n",evenSum,getpid());
    }
}
