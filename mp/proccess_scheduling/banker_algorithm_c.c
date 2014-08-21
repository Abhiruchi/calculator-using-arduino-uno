#include <stdio.h>

int main()
{
	int i, j, k, front, rear, n, m;
	int avail[10], max_need[50][10], allocated[50][10];
	int q_process[50] = {0};
	int q_ans[50] = {0};
	front = 0;
	rear = k = -1;
	
	printf("Enter the number of processes and number of resources:\n");
	scanf("%d%d", &n, &m);
	
	printf("Enter the Allocated Resources for processes one by one:\n");
	for (i = 0; i < n; i++) {
		q_process[++rear] = i + 1;
		for (j = 0; j < m; j++) {
			scanf("%d", &allocated[i][j]);
		}
	}

	printf("Enter the Max. Need resources for processes one by one:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &max_need[i][j]);
		}
	}
	
	printf("Enter the initially available resources:\n");
	for (i = 0; i < m; i++) {
		scanf("%d", &avail[i]);
	}
	
	int flag = 1, flag_pro[10] = {0};
	int cnt = 0;
	
	while (front < 50) {
		flag = 1;
		i = q_process[front%n] - 1;
		if (flag_pro[i] == 0) {
			for (j = 0; j < m; j++) {
				if (allocated[i][j] + avail[j] < max_need[i][j]) {
					flag = 0;
				}
			}
			if (flag == 1) {
				flag_pro[i] = 1;
				for (j = 0; j < m; j++) {
					avail[j] += allocated[i][j];
				}
				q_ans[++k] = q_process[front%n];
			}
		}
		front++;
	}	
	
	printf("Order in which processes execute: \n");
	for (i = 0; i < n; i++) {
		printf("%d ", q_ans[i]);
	}
	printf("\nFinally Available Resources:\n");
	for (i = 0; i < m; i++) {
		printf("%d ", avail[i]);
	}
	printf("\n");
	if (k != n - 1) {
		printf("Deadlock\n");
	}
	getch();
	return 0;
}
			
	
	
	
	
