#include <stdio.h>
int main(){
	int n,k,i,j,count=0;
	scanf("%d %d", &n,&k);
	int a[n-1];
	for(i=0;i<n-1;i++){
		a[i]=i+2;
	}

	for(i=0;i<n-1;i++){
		for(j=i;j<n-1;j++)
			if(a[j]%a[i]==0&&a[j]>0){
				a[j]=-a[j];
				count++;
				if(count==k){
					printf("%d", -a[j]);
				}
			}
	}

}
