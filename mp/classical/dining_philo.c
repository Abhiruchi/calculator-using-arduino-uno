#include <stdio.h>
int n;
struct node {
	int p[100][2];
	int var;
};

void show(struct node *, int n);

int main()
{
	int i, ch;
	struct node s;
    
    printf("enter number of philosophers");
    scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		s.p[i][0] = 1;
		s.p[i][1] = 1;
	}
	
	printf("Press 0.Exit 1.See next step \n");
	
	scanf("%d", &ch);
	
	s.var = 0;
	
	while (ch) {
		
		show(&s, n);
		scanf("%d", &ch);
	}
	
	return 0;
}

void show(struct node *p, int n) {
	int k, m;
	k = (p->var);
	m = ((p->var) + 2) % n; 
	printf("Philosopher %d and %d are dining \n", k, m);
    (p->var)++;	
	p->var %= n;
}

		
	
	
	
	
	
	
