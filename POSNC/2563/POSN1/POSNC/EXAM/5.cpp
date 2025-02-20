#include <stdio.h>
#include <string.h>
int main(){
	char str[20];
	printf("Enter string : ");
	gets(str);
	int i;
	for(i=0;i<strlen(str);i++){
		if(str[i]==' ')
			printf("%c", str[i]);
		else
			printf("%c", str[i]+1);
	}
}
