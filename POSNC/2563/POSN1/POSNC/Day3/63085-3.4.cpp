#include <stdio.h>
int i=2,itisprime=1,count=0;
int n,j=2;
int main(){
	printf("Enter \"n\" : ");
	scanf("%d", &n);
	printf("\n");
	while(i<=n){
		while(j<i){
			if(i%j==0)
				itisprime=0;
			j++;
		}
		if(itisprime){
			printf("%d\t", i);
			count++;
		}
		itisprime=1;
		i++;
		j=2;
	}
	printf("\n\nThere are %d prime number from 1 to %d.", count, n);
}
