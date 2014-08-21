#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[20],burst[20];
    int n, i;
    float tat, awt =0.0, bur = 0.0, t =0.0;
    
    printf("enter number of proceess");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("enter arrival and burst time of %d process", i + 1);
        scanf("%d %d", &arr[i], &burst[i]);
    }
  
    for (i = 0; i < n - 1; i++) {
        t = t + burst[i];
        while (t < arr[i + 1]) {
              t++;
        }
        awt =  awt + t - arr[i + 1];
    }
    
    awt = awt / n;
    
    printf("awt is %f\n", awt);
    for (i = 0; i < n; i++) {
        bur = bur + burst[i];
    }
    
    tat = awt + (bur / n);
    printf("tat is %f\n", tat);
    getch();
    return 0;
}
    
    
    
