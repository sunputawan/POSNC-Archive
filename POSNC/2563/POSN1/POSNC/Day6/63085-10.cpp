#include <stdio.h>
#include <string.h>
char s1[20]={};
char s2[20]={};
int i;
int main(){
	printf("***********************************************\n");
	printf("Input String1 : ");
	scanf("%s", s1);
	printf("Input String2 : ");
	scanf("%s", s2);
	printf("***********************************************\n");
	printf("%-29s= ", "Result of even position");
	for(i=0;i<strlen(s1)||i<strlen(s2);i++){
		if(i%2==1){
			if(s1[i]!='\0')
				printf("%c", s1[i]);
			if(s2[i]!='\0')
				printf("%c", s2[i]);
		}
	}
	printf("\n%-29s= ", "Result of odd position");
	for(i=0;i<strlen(s1)||i<strlen(s2);i++){
		if(i%2==0){
			if(s1[i]!='\0')
				printf("%c", s1[i]);
			if(s2[i]!='\0')
				printf("%c", s2[i]);
		}
	}printf("\n%-29s= ", "Result of String 1&2");
	for(i=0;i<strlen(s1)||i<strlen(s2);i++){
			if(s1[i]!='\0')
				printf("%c", s1[i]);
			if(s2[i]!='\0')
				printf("%c", s2[i]);
	}
	printf("\n%-29s= ", "Result of Upper String 1&2");
	for(i=0;i<=strlen(s1);i++){
			if(s1[i]!='\0'){
				if(s1[i]>=97)
					printf("%c", s1[i]-32);
				else
					printf("%c", s1[i]);
			}
			else
				printf(" ");
	}
	for(i=0;i<strlen(s2);i++){
			if(s2[i]!='\0'){
				if(s2[i]>=97)
					printf("%c", s2[i]-32);
				else
					printf("%c", s2[i]);
			}
	}
	printf("\n%-29s= ", "Result of Lower String 1&2");
	for(i=0;i<=strlen(s1);i++){
			if(s1[i]!='\0'){
				if(s1[i]<=90)
					printf("%c", s1[i]+32);
				else
					printf("%c", s1[i]);
			}
			else
				printf(" ");
	}
	for(i=0;i<strlen(s2);i++){
			if(s2[i]!='\0'){
				if(s2[i]<=90)
					printf("%c", s2[i]+32);
				else
					printf("%c", s2[i]);
			}
	}
		printf("\n%-29s= ", "Result of Reverse string");
	for(i=0;i<=strlen(s1);i++){
			if(s1[i]!='\0'){
				if(s1[i]<=90)
					printf("%c", s1[i]+32);
				else
					printf("%c", s1[i]-32);
			}
			else
				printf(" ");
	}
	for(i=0;i<strlen(s2);i++){
			if(s2[i]!='\0'){
				if(s2[i]<=90)
					printf("%c", s2[i]+32);
				else
					printf("%c", s2[i]-32);
			}
	}
	printf("\n***********************************************\n");
}
