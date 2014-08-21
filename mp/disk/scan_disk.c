#include <stdio.h>

int main()
{
	int n;
	int i, j ,t;
	int a[1000];
	int h;

	printf("Initial Head position  ");
	scanf("%d", &h);
	scanf("%d", &n);

	for(i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	a[n] = h;
	n++;
	for(i = 0; i < n; i++) {
            for (j = 0; j < n -i-1 ; j++) {
                    if (a[j] > a[j+1]) {
                        t = a[j];
                        a[j] = a[j+1];
                        a[j+1] = t;
                    }
            }
        }

	for(i = 0; i < n; i++) {
		if(a[i] == h) {
			h = i;
			break;
		}
	}
		
int s = 0, k;
	for(i = h; i >= 0; i--) 
	{printf("%d\n", a[i]);
	if (i > 0) {
	if (a[i] - a[i-1] > 0)
	s = s + a[i] - a[i-1];
	else
	s = s + (-1)*(a[i]- a[i-1]);
    }
}
	printf("0\n");
	s = s + a[0];
	for(i = h +1; i < n; i++) {
		printf("%d\n", a[i]);
		if (i > h + 1) {
			if (a[i] - a[i-1] > 0)
	s = s + a[i] - a[i-1];
	else
	s = s + (-1)*(a[i]- a[i-1]);
    }}
    s = s + a[h+1];
    printf("total head movement %d", s);
getch();
	return 0;
}
