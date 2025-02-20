#include <stdio.h>
#include <string.h>
int h,w,n,i,j;
char b;
char s[20]={};
int main(){
	printf("Enter String : ");
	scanf("%s", s);
	printf("Height String : ");
	scanf("%d", &h);
	printf("Width String : ");
	scanf("%d", &w);
	printf("Border Character : ");
	scanf(" %c", &b);
	printf("Border width : ");
	scanf("%d", &n);	
	for(i=0;i<n;i++){
		for(j=0;j<2*n+w*strlen(s);j++)
			printf("%c", b);
		printf("\n");
	}
	for(i=0;i<h;i++){
		for(j=0;j<n;j++)
			printf("%c", b);
		for(j=0;j<w;j++)
			printf("%s", s);
		for(j=0;j<n;j++)
			printf("%c", b);
		printf("\n");
	}
	for(i=0;i<n;i++){
		for(j=0;j<2*n+w*strlen(s);j++)
			printf("%c", b);
		printf("\n");
	}
}
