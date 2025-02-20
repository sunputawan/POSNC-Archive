#include <stdio.h>
#include <string.h>
int main(){
	int i,j,l,w,count=0;
	char s[20];
	printf("Enter curtain length : ");
	scanf("%d", &l);
	printf("Enter curtain width : ");
	scanf("%d", &w);
	printf("Enter string (max=20) : ");
	scanf("%s", s);
	int remain=0;
	printf("\n");
	for(i=0;i<w;i++){
		count=0;
		while(count<l){
			printf("%c", s[remain%strlen(s)]);
			count++;
			remain++;
		}
		printf("\n");
	}
}
