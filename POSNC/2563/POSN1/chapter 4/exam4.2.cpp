#include <stdio.h>
int total(int,int);
int h,m;
int main(){
	printf("Please input your parking time (Hour:minute): ");
	scanf("%d%*c%d", &h,&m);
	printf("The total is %d baht.", total(h,m));
}
int total(int h, int m){
	if(m>0)
		h++;
	if(h==0)
		return 0;
	if(h>0)
		return ((h-1)*30);
}
