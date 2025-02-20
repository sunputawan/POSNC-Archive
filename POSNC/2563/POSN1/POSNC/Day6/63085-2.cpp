#include <stdio.h>
char s[20];
int i;
int main(){
	printf("Enter string : ");
	scanf("%s", s);
	for(i=0;i<20;i++){
		if(s[i]>=97)
			s[i]-=32;
		else
			s[i]+=32;
	}
	printf("%s", s);
}
