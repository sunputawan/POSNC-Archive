#include <stdio.h>
int i,n;
int counteven = 0,countodd = 0;
int main(){
	for(i=0;i<5;i++){
		printf("Enter integer%d : ", i+1);
		scanf("%d", &n);
		if(n%2==0)
			counteven++;
		else
			countodd++;
	}
	printf("There are %d evens and %d odds.", counteven, countodd);
}
