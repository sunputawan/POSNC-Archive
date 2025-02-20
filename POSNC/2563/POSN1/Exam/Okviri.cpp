#include <stdio.h>
#include <string.h>
int main(){
	char s[15];
	int i;
	scanf("%s", s);
	for(i=0;i<strlen(s);i++){
		char a='#';
		if(i%3==2)
			a='*';
		printf("..%c.", a);
	}
	printf(".\n");
	for(i=0;i<strlen(s);i++){
		char a='#';
		if(i%3==2)
			a='*';
		printf(".%c.%c", a,a);
	}
	printf(".\n");
	for(i=0;i<strlen(s);i++){
		char a='#';
		if(i%3==2)
			a='*';
		printf("%c.%c.", a,s[i]);
	}
	if(strlen(s)%3==0)
		printf("*");
	else
		printf("#");
	printf("\n");
	for(i=0;i<strlen(s);i++){
		char a='#';
		if(i%3==2)
			a='*';
		printf(".%c.%c", a,a);
	}
	printf(".\n");
	for(i=0;i<strlen(s);i++){
		char a='#';
		if(i%3==2)
			a='*';
		printf("..%c.", a);
	}
	printf(".");
}
