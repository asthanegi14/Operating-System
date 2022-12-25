#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int n;
    printf("Enter total no of processes");
    scanf("%d", &n);

    int at[n], bt[n], rem_bt[n], sq = 0;
    float tat, wt;
    printf("enter arival time.....\n");
    for (int i = 0; i < n; i++)
    {
        printf("at[%d] = ", i);
        scanf("%d", &at[i]);
    }

    printf("enter burst time.....\n");
    for (int i = 0; i < n; i++)
    {
        printf("bt[%d] = ", i);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    int tc;
    printf("enter time quantum = ");
    scanf("%d", &tc);

    int count = 0, temp, x = n, total = 0;
    float awt, atat;

    printf("at\t\tbt\t\ttat\t\twt\n");
    for (int i = 0, total = 0; x != 0;)
    {
        if (rem_bt[i] <= tc && rem_bt[i] > 0)
        {
            total += rem_bt[i];
            rem_bt[i] = 0;
            count = 1;
        }
        else if (rem_bt[i] > 0)
        {
            rem_bt[i] -= tc;
            total += tc;
        }
        if (rem_bt[i] == 0 && count == 1)
        {
            x--;
            printf("%d\t\t%d\t\t%d\t\t%d\n", at[i], bt[i], total - at[i], total - at[i] - bt[i]);
            tat += total - bt[i];
            wt += total - at[i] - bt[i];
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    printf("Average wt = %f\nAverage tat = %f\n", wt / n, tat / n);
    return 0;
}
