#include <stdio.h>
#include <stdlib.h>

#define limit 20

typedef struct node {
	int mutex;
	int empty;
	int full;
}
semaphore;

void producer(semaphore *p);
void consumer(semaphore *p);
void signal(semaphore *p);
void wait(semaphore *p);

int main()
{
	int ch, flag = 1;
	semaphore s;
	
	s.mutex = 0;
	s.empty = 1;
	s.full = 0;
	
	while (1) {
		printf("Enter:\n1.Producer Call\n2.Consumer Call\n3.Continue without change\n4.Exit\n");
	
		scanf("%d", &ch);
	
		if (ch == 3) {
			ch = flag;
		} else if (ch == 4) {
			return 0;
		}
		
		switch (ch) {
			case 1: producer(&s);
				break;
			case 2: consumer(&s);
				break;
			default: break;
		}
		flag = ch;
	}
	
	return 0;
}

void producer(semaphore *p) 
{
	if (p->full == 0) {
		printf("Producer produces %d\n", p->mutex + 1);
		signal(p);	
	} else {
		printf("Producer wait!\n");
	}	
}

void consumer(semaphore *p) 
{
	if (p->empty == 0) {
		printf("Consumer consumes %d \n", p->mutex);
		wait(p);
	} else {
		printf("Consumer wait!\n");
	}	
}

void signal(semaphore *p)
{
	if ((p->mutex) < limit) {
		(p->mutex)++;
		if ((p->mutex) == limit) {
			p->full = 1;
			
		}
		p->empty = 0;
	}
}

void wait(semaphore *p) 
{
	if ((p->mutex) > 0) {
		(p->mutex)--;
		if (p->mutex == 0) {
			p->empty = 1;
		}
		p->full = 0;
	}
}	

