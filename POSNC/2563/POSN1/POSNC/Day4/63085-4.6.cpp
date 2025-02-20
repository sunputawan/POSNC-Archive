#include <stdio.h>
int n,i,j,count=1;
int main(){
	printf("Enter a number : ");
	scanf("%d", &n);
	if(n>200){
		printf("Invalid input!");
		return 0;
	}
	j=65;
	for(i=1;i<=n;i++){
		for(;j<i*(i+1)/2+65;j++){
			printf("%c", j);
			if(j>=90)
				j=64;
			if(count==i+1)
				break;
			count++;
		}
		printf("\n");
		count =1;
	}
}
