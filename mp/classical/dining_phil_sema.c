#include <stdio.h>

#define limit 100
#define thinking 0
#define eating 1

typedef struct node {
	int mutex;
	int empty;
	int full;
	int var;
}
semaphore;

void request(semaphore *p);
void waiter(semaphore *p);
void wait(semaphore *p);
void show(semaphore *p, int, int);

int main()
{
	int n;
    int philosophers[100] = {0};
	int states[100][2];
	int i, ch;
	semaphore s;
	s.mutex = s.full = 0;
	s.empty = 1;
		
	for (i = 0; i < n; ++i) {
		states[i][0] = 0;
		states[i][1] = 0;
	}
	printf("enter the number of philosophers");
	scanf("%d", &n);
	s.var = 0;
	int c = 0;
	printf("Enter 0 to exit!\n");
	while (scanf("%d", &ch) == 1 && ch) {
		int i, j;
		i = (s.var);
		j = ((s.var) + c + 2) % n; 
		if (i - j == 1 || i == j) {
			j  = (j+3) % n;
		} else if (j - i == 1 || i == j) {
			i = (i+3) % n;
		}			
		show(&s, i, j);
		c++;
		if (c%2 == 0) {
			s.var++;
			s.var = s.var%n;
		}	
	}
	
	return 0;
}

void show(semaphore *p, int i, int j)
{
	printf("Philosopher %d and %d are dining \n", i+1, j+1);
}
	
