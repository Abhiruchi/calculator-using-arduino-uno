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
	//Optimal
	int l;
	
	for (l = 0; l < strlen(order); l++) {
		int last = -1, lastindx = -1;
		for (i = 0; i < n; i++) {
			if (pageno[i] == (order[l]-'0')	) {
				break;
			}
		}
		k = 0;
		if (i == n) {
			pagefault++;
			for (i = 0; i < n; i++) {
				if (!pageno[i]) {
					break;
				}
			}
			if (i != n) {
				pageno[i] = order[l]-'0';
			}
			if (i == n) {
				for (i = 0; i < n; i++) {
					if (pageno[i]) {
						for (j = l; j < strlen(order); j++) {
							if (pageno[i] == order[j]-'0') {
								if (j > last) {
									last = j;
									lastindx = i;
								}
								break;
							}
						}
					}
				}
				if (lastindx > 0) {
					pageno[lastindx] = order[l] - '0';
				}
			}
		}
		for (j = 0; j < n-1; j++) {
			if (pageno[j]) {
				printf("%d, ", pageno[j]);
			} else {
				break;
			}
		}
		if (pageno[j]) {
			printf("%d", pageno[j]);
		}
		printf("\n");
	}
	printf("Pagefault = %d\n", pagefault);
	getch();
	return 0;
}
	
			
			
