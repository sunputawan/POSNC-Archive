#include <stdio.h>
#include <string.h>
int len[4]={};
char str[4][20];
int i,j;
int main(){
	for(i=0;i<4;i++){
		printf("Enter text%d : ", i+1);
		scanf("%s", str[i]);
		len[i]=strlen(str[i]);
	}
	for(i=0;i<4;i++){
		for(j=0;j<len[i];j++)
			printf("%c", str[i][j]);
		printf(" : %d\n", len[i]);
	}
}
