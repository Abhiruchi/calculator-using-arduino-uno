#include <stdio.h>
int main()
{
    int n, i, arr[20], b = 0, burst[20],arr1[20], burst1[20], t = 0, count = 0, flag1[20], j, wt[20], a, at;
    float awt = 0.0, tat;
    
    printf("enter the number of processes");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("enter the arrival and burst time for process %d", i);
        scanf("%d %d", &arr[i], &burst[i]);
        arr1[i] = arr[i];
        burst1[i] = burst[i];
        flag1[i] = 0;
        b = b + burst[i];
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
    
    t = 0;
    
    while (count != n) {
          a = count;
          for (i = 0; i < n; i++) {
              at = 0;
              if (flag1[i] != 1) {
                 if (arr1[i] <= t) {
                          wt[i] = t - arr1[i];
                          t = t + burst1[i];
                          count++;
                          flag1[i] = 1;
                          at = 1;
                 }
              }
              if (at == 1) {
                    break;
              }
          }
          if (a == count) {
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
    
    
    
    
    
    
    
    
    
    
    
