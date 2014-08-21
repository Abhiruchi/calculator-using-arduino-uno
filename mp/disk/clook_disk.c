#include <stdio.h>
#include <conio.h>
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
		

	for(i = h; i < n; i++)
		printf("%d\n", a[i]);
	for(i = 0; i < h -1; i++)
		printf("%d\n", a[i]);
getch();
	return 0;
}
