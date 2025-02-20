#include<stdio.h>
char a,b,t;
int main(){
	scanf("%c%c", &a,&b);
	printf("%c%c%c", a,b,t);
	t=a,a=b,b=t;
	printf("%c%c%c", a,b,t);
}
