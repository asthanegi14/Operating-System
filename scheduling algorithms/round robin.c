#include<stdio.h>
 
int main()
{
      int i, p, total = 0, x, counter = 0, tq;
      int wt = 0, tat = 0, at[10], bt[10], temp[10];
      float avgWt, avgTat;
      printf("Enter Total Number of Processes: ");
      scanf("%d", &p);
      x = p;
      for(i = 0; i < p; i++)
      {
            printf("Arrival Time of process %d: ",i+1);
 
            scanf("%d", &at[i]);
 
            printf("Burst Time of process %d: ",i+1);
 
            scanf("%d", &bt[i]);
 
            temp[i] = bt[i];
      }
 
      printf("\nEnter Time Quantum: ");
      scanf("%d", &tq);
      
      for(int i=0;i<p-1;i++){
          for(int j=0;j<p-i-1;j++){
              if(at[j+1]<at[j]){
                  int temp = at[j+1];
                  at[j+1]=at[j];
                  at[j]=temp;
                  
                  int temp2 = bt[j+1];
                  bt[j+1]=bt[j];
                  bt[j]=temp2;
              }
          }
      }
      
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= tq && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - tq;
                  total = total + tq;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, bt[i], total - at[i], total - at[i] - bt[i]);
                  wt += total - at[i] - bt[i];
                  tat += total - at[i];
                  counter = 0;
            }
            if(i == p - 1)
            {
                  i = 0;
            }
            else if(at[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 
      avgWt = wt * 1.0 / p;
      avgTat = tat * 1.0 / p;
      printf("\nAverage Waiting Time: %f", avgWt);
      printf("\nAvg Turnaround Time: %f\n", avgTat);
      return 0;
}
