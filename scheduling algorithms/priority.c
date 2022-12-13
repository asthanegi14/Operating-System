#include <stdio.h>

int main()
{
    int p,bt[p],pro[p],pri[p];
    int wt[p],tat[p],total;
    float avg_tat,avg_wt;
    printf("Enter total process: ");
    scanf("%d",&p);
    printf("Enter Burst time for process ");
    for(int i=0;i<p;i++){
        printf("p%d = ",i+1);
        scanf("%d",&bt[i]);
        pro[i]=i+1;
    }
    
    printf("Enter priority of process ");
    for(int i=0;i<p;i++){
        printf("p%d = ",i+1);
        scanf("%d",&pri[i]);
    }
   for(int i=0;i<p;i++)
    {
        int pos=i;
        for(int j=i+1;j<p;j++)
        {
            if(pri[j]<pri[pos])
                pos=j;
        }
  
        int temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=pro[i];
        pro[i]=pro[pos];
        pro[pos]=temp;
        
        temp=pri[i];
        pri[i]=pri[pos];
        pri[pos]=temp;
    }
    wt[0]=0;            
  
   
    for(int i=1;i<p;i++)
    {
        wt[i]=0;
        for(int j=0;j<i;j++)
            wt[i]+=bt[j];
  
        total+=wt[i];
    }
  
    avg_wt=(float)total/p;      
    total=0;
  
    printf("\nProcesst    Burst Time    \tWaiting Time\tTurnaround Time\tPriority");
    for(int i=0;i<p;i++)
    {
        tat[i]=bt[i]+wt[i];   
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d\t\t%d",pro[i],bt[i],wt[i],tat[i],pri[i]);
    }
  
    avg_tat=(float)total/p;    
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
    return 0;
}


