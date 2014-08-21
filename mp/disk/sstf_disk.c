#include <stdio.h>
#include <conio.h>
int mod(int t)
{
	if(t > 0)
		return t;
	t = -t;
	return t;
}

int main()
{
	int n, s;
	int i, j ,k;
	int d, t, d1;
	int a[1000][2];
	int h, h1;

	printf("Initial Head position  ");
	scanf("%d", &h);
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i][0]);
		a[i][1] = 1;
	}
    s = 0;
	for(i = 0; i < n; i++) {
		d = 1000;
		for(j = 0; j < n; j++) {
			if(a[j][1] == 1) {
				t = h - a[j][0];
				d1 = mod(t);
				if(d > d1) {
					h1 = j;
					d = d1;
				}
			}
		}
		printf("Movement = %d\n", a[h1][0] - h);
		if (a[h1][0] - h >= 0) 
		s = s + a[h1][0] - h;
		else
		s = s + (-1)*(a[h1][0] - h);
		h = a[h1][0];
		a[h1][1] = 0;
		printf("%d\n", h);
	}
 
    printf("total head movement %d", s);
    getch();
	return 0;
}
