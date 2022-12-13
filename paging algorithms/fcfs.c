#include <stdio.h>
int main()
{
    int pv[10], pf = 0, m, n, s, pages, f,hit;
    printf("Enter the number of Pages: ");
    scanf("%d", &pages);
    printf("\nEnter reference string values:\n");
    for( m = 0; m < pages; m++){
       printf("%d: ", m + 1);
       scanf("%d", &pv[m]);
    }
    printf("\nWhat are the total number of blocks: ");
    {
       scanf("%d", &f);
    }
    int temp[f];
    
    for(m = 0; m < f; m++){
      temp[m] = -1;
    }
    for(m = 0; m < pages; m++)
    {
      s = 0;
      for(n = 0; n < f; n++)
       {
          if(pv[m] == temp[n])
             {
                hit++;
                s++;
                pf--;
             }
       }     
       pf++;
       if((pf <= f) && (s == 0))
          {
            temp[m] = pv[m];
          }   
       else if(s == 0)
          {
            temp[(pf - 1) % f] = pv[m];
          }
          printf("\n");
          for(n = 0; n < f; n++)
           {     
             printf("%d\t", temp[n]);
           }
    } 
    printf("\nTotal Page Faults:%d\n", pf);
    printf("\nTotal no of hit:%d\n",hit);
    return 0;
}
