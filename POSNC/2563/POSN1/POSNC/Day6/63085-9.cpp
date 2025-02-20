#include <stdio.h>
#include<string.h>
int count,i;
char a[50];
char b[50]={};
int main(){
	printf("Input String : ");
	scanf("%s", a);
	for(i=0;i<strlen(a);i++){
		b[i]=a[strlen(a)-i-1];
	}
	switch(strcmp(a,b)){
		case 0 :
			printf("%s is a Palindrome", a);
			break;
		default :
			printf("%s is not a Palindrome", a);
			break;
	}
}
