#include <stdio.h>

int max(int *C,int t)
{
	int i,max,k = 0,l = 0;
	for(i = 0 ;i < t;i++){
		if(C[i] == 0){
			l++;
		}
	}
	if( l == t){
		return -1;
	}else{
		max = C[0];
		for(i = 0;i < t;i++){
			if(C[i] >= max){
				max = C[i];
				k = i;
			}
		}
		return k;
	}
}
int find(int *B,int a,int t){
	int i,d = -1;
	for(i = 0;i < t;i++){
		if(B[i] == a){
			d = i;
			break;
		}
	}
	return d;
}
void replace(int *B,int a,int t)
{
	int i;
	for(i = 0;i < t-1;i++){
		B[i] = B[i+1];
	}
	B[i] = a;

}
int min(int *C,int t)
{
	int i,k,max;
	max = C[0];
	for(i = 0;i < t;i++){
		if(C[i] <= max){
			max = C[i];
			k = i;
		}
	}
	return k;
}
int search(int *A,int *B,int t,int m,int n)
{
	int C[10],r = 0,i,j,count = 0,q = -1;
	for(i = 0;i < t;i++){
		count = 0;
		for(j = m+1;j < n;j++){
			if(A[j] == B[i]){
				
				break;
			}else{
				count++;
			}
		}
		C[r++] = count;
	}
	q = max(C,r);
	return q;
}
	
int main()
{
	int A[50],i, n, t,g,D[50],B[50],k = 0,b = 0,count = 0,q,fin,j;
	
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&A[i]);
	}
	printf("Enter no. of frames:");
	scanf("%d",&t);

	for(i = 0;i < t;i++){
		B[k++] = A[i];
		D[b++] = i;
		count++;
		for(j = 0;j < k;j++){
			printf("%d",B[j]);
		}
		printf("\n");
	}
	for(i = t;i < n;i++){
		fin = find(B,A[i],t);
		if(fin == -1){
			q = search(A,B,t,i,n);
			if(q != -1){
				B[q] = A[i];
				D[q] = i;
				count++;
			}else{
				g = min(D,t);
				B[g] = A[i];
				D[g] = i;
				count++;
			}
		}else{
			D[fin] = i;
		}
		for(j = 0;j < t;j++){
			printf("%d ",B[j]);
		}
		printf("\n");
	}
		
	printf("%d\n",count);
	return 0;
}
	
