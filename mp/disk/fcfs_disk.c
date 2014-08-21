#include <stdio.h>
#include <conio.h>
int main()
{
	int n;
	int i;
	int s = 0;
	int a[1000];
	int h;

	printf("Initial Head position  ");
	scanf("%d", &h);
	scanf("%d", &n);

	for(i = 0; i < n; i++) 
		scanf("%d", &a[i]);

	printf("%d\n", h);
	for(i = 0; i < n; i++) 
		printf("%d\n", a[i]);
		s = 0;
		for(i = 1; i < n; i++) {
        if (a[i] - a[i-1] >= 0)
		s = s + a[i] - a[i - 1];
		else
		s = s + (-1)*(a[i]-a[i-1]);
       }
       if (a[0] - h >= 0)
       s = s + a[0] - h;
       else
       s = s + (a[0] - h)*(-1);
  printf("total head movement %d", s);
    getch();
	return 0;
}
