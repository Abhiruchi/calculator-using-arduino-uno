#include <stdio.h>
int main()
{
    int n, arr[20][20], a, b, c, i, count = 0;
    
    printf("enter the number of processes");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        arr[i][0] = i;
        
        printf("enter allocated and need of resources of process %d", i);
        scanf("%d %d %d %d %d %d", &arr[i][1],  &arr[i][2],  &arr[i][3],  &arr[i][4],  &arr[i][5],  &arr[i][6]);
        
        arr[i][7] = arr[i][4] - arr[i][1];
        arr[i][8] = arr[i][5] - arr[i][2];
        arr[i][9] = arr[i][6] - arr[i][3];
        
        arr[i][10] = 0;
    }
    
    printf("enter the available resources");
    scanf("%d %d %d", &a, &b, &c);
    while (count != n) {
          for (i = 0; i < n; i++) {
              if (arr[i][10] != 1) {
                 if (arr[i][7] <= a && arr[i][8] <= b && arr[i][9] <= c) {
                      arr[i][10] = 1;
                      a = a + arr[i][1];
                      b = b + arr[i][2];
                      c = c + arr[i][3];
                      printf("process %d executed", i);
                      count++;
                 }
              }
          }  
    }   
    
    getch();
    return 0;
}      
        
        
        
        
            
            
          
    
