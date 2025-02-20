#include <stdio.h>
void sort(int [],int);
void swap(int *,int *);
void permute(int *,int,int);
int main(){
	int m,n;
	int i,j,k=0;
	scanf("%d", &n);
	scanf("%d", &m);
	int x[m],t[n-m];
	for(i=0;i<m;i++){
		scanf("%d", &x[i]);
	}
	sort(x,m);
	for(i=1;i<=n;i++){
		int contain=0;
		for(j=0;j<m;j++){
			if(i==x[j])
				contain=1;
		}
		if(!contain){
			t[k]=i;
			k++;
		}
	}
/*	for(i=0;i<n-m;i++){
		printf("%d ", t[i]);
	}*/
	permute(t,0,n-m);
}
void sort(int a[],int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])
				swap(&a[i],&a[j]);
}
void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void permute(int *a,int start,int sizea){
  int i,j;
  if(start==sizea-1){
    	for(i=0;i<sizea;i++)
      		printf("%d ", a[i]);
	  	printf("\n");
	}   
  else{
    for (i=start;i<sizea;i++){
      swap((a+start),(a+i)); //swap the characters
      permute(a,start+1,sizea); //recursively call
      swap((a+start),(a+i)); //backtrack
    }
  }
}
