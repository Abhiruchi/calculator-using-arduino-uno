#include<stdio.h>
#include <conio.h>
struct proc
{
	int pid, at,bt,wt,tat,rbt;
	int flag,flag1;
};

struct proc p1[10];
int minimum1();

int i, j, k, n, no, m;
float atat = 0.0, awt = 0.0;
int tbt = 0;

int main()
{
	int minv,locv,mins,locs;
	
	printf("Enter the number of processes: \n");
	scanf("%d", &n);
	
	printf("Enter Proccess information in the following order: \n");	
	printf("Enter Process id, Arrival Time and Burst Time: \n");
	
	for (i = 0; i < n; i++) {
        	p1[i].wt = 0;
        	p1[i].tat = 0;
       		p1[i].flag = 0;
        	p1[i].flag1 = 0;
        	
        	scanf("%d %d %d", &p1[i].pid, &p1[i].at, &p1[i].bt);
        	
        	tbt += p1[i].bt;
        	p1[i].rbt = p1[i].bt;
	}
	
	minv = p1[0].at;
	locv = 0;

	for (i = 1; i < n; i++) {
		if (p1[i].at < minv) {
			locv = i;
			minv = p1[i].at;
		}
	}
	
	for (i = 0; i < n; i++) {
		if (p1[i].at == minv) {
			p1[i].flag1 = 1;
		}
	}

	mins = p1[0].bt;
	locs = 0;
	
	for (i = 0; i < n; i++) {
		if (p1[i].flag1 == 1 && p1[i].bt < mins) {
			mins = p1[i].bt;
			locs = i;
		}
	}

	for (i = minv; i < tbt+minv; i++) {
		for (j = 0; j < n; j++) {
            		if (p1[j].rbt > 0 && p1[j].at <= i) {
                		p1[j].flag = 1;
            		}
        	}
    		no = minimum1();
		p1[no].rbt=p1[no].rbt-1;
   
    		for (k = 0; k < n; k++) {
        		if(p1[k].rbt > 0 && p1[k].at <= i && k != no) {
                		p1[k].wt++;
            		}
    		}
	}
	
	for (i = 0; i < n; i++) {
        	awt += p1[i].wt;
    	}
    	
	awt = awt/n;
	
	for (i = 0; i < n; i++) {
        	p1[i].tat = p1[i].wt + p1[i].bt;
        	atat += p1[i].tat;
        	
        	printf("\n process : %d  Waiting time : %d  Turn around time: %d", p1[i].pid, p1[i].wt, p1[i].tat);
    	}
    	
    	atat = atat/n;
    	printf("\nAverage Waiting Time = %.2f\nAverage Turn Around Time = %.2f\n", awt, atat);
        getch();
}

int minimum1()
{
	int loc, z;
	int mini;
	mini = 99;
	loc = -1;
	for (z = 0; z < n; z++) {
	if (p1[z].rbt > 0 && p1[z].at <= i && p1[z].rbt < mini) {
		mini = p1[z].rbt;
		loc=z;
		}
	}
	return loc;
}


