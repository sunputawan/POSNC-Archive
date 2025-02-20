#include <stdio.h>
int age,count, height;
int main(){
	int i=1;
	while(i<=50){
		printf("NO.%d\n", i);
		printf("age = ");
		scanf("%d", &age);
		printf("height = ");
		scanf("%d", &height);
		if(age>15&&height>=175)
			count++;
		i++;
	}
	printf("%d", count);
}
