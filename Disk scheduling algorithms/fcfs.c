#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
int main()
{
    int n;
    printf("enter array size = ");
    scanf("%d", &n);
    int arr[n];
    printf("enter array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int head;
    printf("enter head = ");
    scanf("%d", &head);

    int dis = 0, curr = 0;

    for (int i = 0; i < n; i++)
    {
        curr = arr[i];
        dis += abs(curr - head);

        head = curr;
    }
    printf("head is = %d\nDistance = %d\n", head, dis);
    return 0;
}
