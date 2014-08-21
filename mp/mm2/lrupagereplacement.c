#include <stdio.h>
#include <string.h>
#include <conio.h>
int main()
{
	int pageno[100] = {0};
	char order[100];
	int i, j, k, n, pagefault = 0;
	printf("Enter frame size:\n");
	scanf("%d", &n);
	scanf("%s", order);
	int front, rear;
	front = rear = 0; 
	//LRU
	int l;
	
	for (l = 0; l < strlen(order); l++) {
		for (i = 0; i < n; i++) {
			if (pageno[i] == (order[l]-'0')	) {
				break;
			}
		}
		if (i == n) {
			pagefault++;
			for (j = 0; j < n-1; j++) {
				pageno[j] = pageno[j+1];
			}
			pageno[n-1] = order[l]-'0';
		} else {
			for (j = i; j < n-1; j++) {
				pageno[j] = pageno[j+1];
			}
			pageno[n-1] = order[l]-'0';
		}
		for (j = 0; j < n-1; j++) {
			if (pageno[j]) {
				printf("%d, ", pageno[j]);
			}
		}
		if (pageno[n-1]) {
			printf("%d\n", pageno[n-1]);
		}
	}
	printf("Pagefault = %d\n", pagefault);
	getch();
	return 0;
}
	
			
			
