#include <stdio.h>
int prime(int);
int main(){
	int t,n;
	scanf("%d", &n);
	t=prime(n);
	if(t)
		printf("yes");
	else
		printf("no");
}
int prime(int n){
	int i,count=0;
	for(i=1;i<=n;i++){
		if(n%i==0)
			count++;
	}
	if(count==2)
		return 1;
	else
		return 0;
}
