#include<stdio.h>
void findWaitingTime(int processes[], int n, int bt[], int tat[], int wt[])
{
	wt[0] = 0;
	for (int i = 0; i < n ; i++ )
		wt[i] = tat[i]-bt[i];
}
void findCalculationTime( int processes[], int n, int bt[], int ct[])
{
	for (int i = 1; i < n ; i++){
		ct[0] = bt[0];
		ct[i] = ct[i-1]+bt[i];
	}
}
void findTurnAroundTime(int processes[], int n, int ct[], int at[], int tat[]){
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
    }
}
void findavgTime( int processes[], int n, int bt[], int at[])
{
	int wt[n], ct[n], tat[n], total_wt = 0, total_tat = 0,total_ct=0;
	findCalculationTime(processes, n, bt,ct);
	findTurnAroundTime(processes, n, ct, at, tat);
	findWaitingTime(processes, n, bt, tat, wt);
	printf("Pros  AT   BT   WT  CT  TAT\n");

	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		total_ct = total_ct + ct[i];
		printf(" %d ",(i+1));
		printf("   %d ", at[i] );
		printf("   %d ", bt[i] );
		printf("   %d",wt[i] );
		printf("   %d",ct[i] );
		printf("    %d\n",tat[i] );
	}
	int s=(float)total_wt / (float)n;
	int t=(float)total_tat / (float)n;
	int u=(float)total_ct / (float)n;
	printf("Average waiting time = %d",s);
	printf("\n");
	printf("Average turn around time = %d ",t);
	printf("\n");
	printf("Average calculation time = %d",u);
}
int main()
{
	int processes[] = { 1, 2, 3, 4, 5};
	int n = 5;

	int burst_time[] = {3, 2, 1, 4, 3};
    int arival_time[] = {0, 1, 2, 3, 4};
	findavgTime(processes, n, burst_time, arival_time);
	return 0;
}

