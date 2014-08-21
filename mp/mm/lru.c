#include <stdio.h>
#define N 100

int main()
{
	int mem[N];
	int m_size = 3;
	int d, i, j, k;
	int n, t;
	int pf = 0;
	scanf("%d", &n);
	k = 0;

	for (i = 0; i < m_size; i++) {
		mem[i] = 0;
	}

	for (i = 0; i < n; i++) {
		scanf("%d", &d);
		for (j = 0; j < m_size; j++) {
			if (mem[j] == d) {
				break;
			}
		}
		if (j == m_size) {
			for (t = 0; t < m_size - 1; t++) {
				mem[t] = mem[t+1];
			}
		printf("Page fault\n");
		pf++;
		mem[t] = d;
		} else {
			for (t = j; t < m_size - 1; t++) {
				mem[t] = mem[t+1];
			}
			mem[t] = d;
			printf("No page fault\n");
		}				
		
		for (t = 0; t < m_size; t++) {
			printf("%d\t", mem[t]);
		}
		printf("\n");
	}
	printf("NO. of page faults = %d\n", pf);
	return 0;
}
