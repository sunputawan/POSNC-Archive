#include <stdio.h>
int max,min,i;
float aver;
int main(){
	int a[5];
	for(i=0;i<5;i++){
		printf("Ente00000r data%d : ",i+1);
		scanf("%d", &a[i]);
		if(i=0)
			min=max=a[i];
		if(a[i]>max)
			max=a[i];
		if(a[i<min])
			min=a[i];
		aver+=(a[i]/5.0);
	}
	printf("max : %d\nmin : %d\naverage : %d", max,min,aver);
}
