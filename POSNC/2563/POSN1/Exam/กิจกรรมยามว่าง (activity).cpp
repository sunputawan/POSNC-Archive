#include <stdio.h>
int select(int n,int k){
	float r=1;
	for(int i=n;i>=(n-k+1);i--){
		r*=i;
	}
	for(int i=1;i<=k;i++){
		r/=i;
	}
	return r;
}
int main(){
	int n;
	scanf("%d", &n);
	int k=n/2;
	if(n%2==0)
		printf("%d", select(n,k));
	else {
		printf("%d", select(n,k)+select(n,k+1));
	}
}
