#include <stdio.h>
#include <string.h>
int expo(int,int);
int main(){
	char n[1000000];
	int r3=0,r11=0;
	scanf("%s", n);
	for(int i=0;i<strlen(n);i++){
		r3+=n[strlen(n)-1-i]-48;
		r11+=(n[strlen(n)-1-i]-48)*expo(-1,strlen(n)-1-i);
	}
/*	for(int i=0;i<strlen(n);i++){
		printf("%d ", (n[strlen(n)-1-i]-48)*expo(-1,i+1));
	}*/
	printf("%d %d", r3%3,(r11+11)%11);
}
int expo(int x,int y){
	int a=x;
	for(int i=0;i<y;i++){
		x*=a;
	}
	return x;
}
