#include <stdio.h>
#include <string.h>
int main(){
	char str[20]={};
	printf("Enter string : ");
	scanf("%s", &str);
	for(int i=0;i<strlen(str);i++){
		if(str[i]!=str[i-1])
			printf("%c", str[i]);
	}
}
