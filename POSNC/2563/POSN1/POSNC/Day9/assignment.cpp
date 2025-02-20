#include <stdio.h>
int main(){
	int a[10],*p,i,sum;
	p=a;
	for(i=0;i<10;i++){
		scanf("%d", p);
		sum+=*p;
		p++;
	}
	printf("%d ", sum);

}
