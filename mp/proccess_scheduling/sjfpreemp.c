#include <stdio.h>

int main()
{
    int n, i, arr[20], burst[20], arr1[20], burst1[20], b = 0, t = 0, a[i], p, wt[20], j, pi[20], count;
    float awt, tat;
    
    printf("enter the number of resources");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("enter arrival and burst time for process %d", i);
        scanf("%d %d", &arr[i], &burst[i]);
        burst1[i] = burst[i];
        arr1[i] = arr[i];
        b = b + burst[i];
        a[i] = 0;
        wt[i] = 0;
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (burst1[j + 1] < burst1[j]) {
                      t = arr1[j + 1];
                      arr1[j + 1] = arr1[j];
                      arr1[j] = t;
                      t = burst1[j + 1];
                      burst1[j + 1] = burst1[j];
                      burst1[j] = t;
            }
        }
    }
    for (i = 0; i < n; i++) {
        pi[i] = arr1[i];
    }
    
    t = 0;
    
    while (t != b)
    {
          for (i = 0; i < n; i++) {
              count = 0;
              if (arr1[i] <= t && a[i] < burst1[i]) {
                         printf("process seq");
                         printf("%d\n", i);
                         a[i] = a[i] + 1;
                         wt[i] = wt[i] + t - pi[i];
                         t = t + 1;
                         pi[i] = t;
                         count = 1;
                         break;
              } 
          }
          if (count == 0) {
                    t++;
          }
    }
    
    for (i = 0; i < n; i++) { 
        printf("%d \n", wt[i]);
        awt = awt + wt[i];
    }
    
    tat = (awt + b) / n;
    awt = awt / n;   
    
    printf("awt and tat is %f and %f", awt, tat);
    
    getch();
    return 0;
}    
    
    
    
    
    
    
    
    
    
    
        
