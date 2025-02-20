#include<stdio.h>
#include <math.h>
int find(int);
int main(){
	int a,b,c;
	scanf("%d%d%d", &a,&b,&c);
	printf("%d", find(a)+find(b)+find(c));
}
int find(int a){
	int m=1,n;
	for(n=0;m<=a;n++){
		m*=2;
	}
	return n-1;
}
