#include <stdio.h>
void swapname(char a[],char b[]){
	char t[20];
	int i;
	for(i=0;i<20;i++){
		t[i]=a[i];
		a[i]=b[i];
		b[i]=t[i];
	}
}
int main(){
	char a[20],b[20];
	scanf("%s ", a);
//	scanf(" %s", b);
	swapname(a,b);
	printf("%s\n%s", a,b);
}
