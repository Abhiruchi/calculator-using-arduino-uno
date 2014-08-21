#include <stdio.h>

int main()
{
    int n, arr[20], burst[20], tq, t, b = 0, p[20], i, wt[20], c[20];
    float awt, tat;
    
    printf("enter the number of processes");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("enter arrival and burst time for process %d", i);
        scanf("%d %d", &arr[i], &burst[i]);
        b = b + burst[i];
        wt[i] = 0;
        p[i] = arr[i];
        c[i] = 0;
    }
    printf("enter the time quantum");
    scanf("%d", &tq);
    
    t = 0;
    
    while (b != t) {
          for (i = 0; i < n; i++) {
              if (arr[i] <= t && c[i] < burst[i]) {
                   if (t != p[i]) {
                      wt[i] = wt[i] + t - p[i]; 
                   }
                   t = t + tq;
                   p[i] = t;
                   c[i] = c[i] + tq;
              } 
          }
    }
                  
    for (i = 0; i < n; i++) {
        awt = awt + wt[i];
    }
    tat = (awt + b)/n ;       
    awt = awt / n;    
    
    printf("avg waiting time and turn around time is %f and %f", awt, tat);
    
    getch();
    return 0;
}
                  
                  
                  
                   
    
