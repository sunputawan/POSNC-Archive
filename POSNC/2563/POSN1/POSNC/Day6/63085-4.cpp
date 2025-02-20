#include <stdio.h>
char a[13]={};
char b[17]={};
int i,j=0;
int main(){

	printf("Enter ID code : ");
	scanf("%s", a);
	printf("%s\n", a);
	for(i=0;i<13;i++){
		if(i==1||i==5||i==10||i==12){
			b[j]='-';
			j++;
		}
		b[j]=a[i];
		j++;
	}
	printf("%s", b);
}
