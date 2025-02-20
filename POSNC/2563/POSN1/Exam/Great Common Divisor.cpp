#include <stdio.h>
int gcd(int,int);
int main(){
	int a,b,max,min;
	scanf("%d %d",&a,&b);
	if(a>b){
		max=a;
		min=b;
	}
	else{
		max=b;
		min=a;
	}
	printf("%d",gcd(max,min));
}
int gcd(int a,int b){
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
