#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
	char a[100];
	char b[100];
	char o;
	scanf("%s ", a);
	scanf("%c", &o);
	scanf("%s", b);
	int x,y;
	if(o=='*'){
		printf("1");
		for(int i=0;i<strlen(a)+strlen(b)-2;i++)
			printf("0");
	}
	if(o=='+'){
		if(strlen(a)>strlen(b)){
			printf("1");
			for(int i=0;i<strlen(a)-strlen(b)-1;i++)
				printf("0");
			printf("%s", b);
		}
		if(strlen(a)<strlen(b)){
			printf("1");
			for(int i=0;i<strlen(b)-strlen(a)-1;i++)
				printf("0");
			printf("%s", a);
		}
		if(strlen(a)==strlen(b)){
			printf("2");
			for(int i=1;i<strlen(a);i++)
				printf("0");
		}
	}
}
