#include <stdio.h>

int search(int *A,int a,int t){
	int i,d = 0;
	for(i = 0;i < t;i++){
		if(A[i] == a){
			d = 1;
			break;
		}
	}
	return d;
}
void replace(int *A,int a,int t)
{
	int i;
	for(i = 0;i < t-1;i++){
		A[i] = A[i+1];
	}
	A[i] = a;

}
int main(){
	int n,q,A[50],t,k = 0,count = 0,i,j,a;
	scanf("%d",&n);
	scanf("%d",&t);
	
	for(i = 0;i < t;i++){
		scanf("%d",&a);
		A[k++] = a;
		n--;
		count++;
		for(j = 0;j < k;j++){
			printf("%d",A[j]);
		}
		printf("\n");
	}
	for(i = 0;i < n;i++){
		scanf("%d",&a);
		q = search(A,a,t);
		if(!q){
			replace(A,a,t);
			count++;
		}
		for(j = 0;j < t;j++){
			printf("%d",A[j]);
		}
		printf("\n");
	}
			
	printf("%d\n",count);
	return 0;
}
