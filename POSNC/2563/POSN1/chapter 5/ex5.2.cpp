#include <stdio.h>
void operate(int);
int main(){
	int n;
	operate(n);
}
void operate(int n){
	printf("Please input \"n\" (even): ");
	scanf("%d", &n);
	if(n%2==0){
		int i,t;
		float a[n];
			for(i=0;i<n;i++){
				printf("Enter data%d : ", i+1);
				scanf("%f", &a[i]);
			}
			for(i=0;i<n;i++)
				printf("%f\t", a[i]);
			for(i=0;i<n;i++){
				if(i%2==0){
					t=a[i];
					a[i]=a[i+1];
					a[i+1]=t;
				}
			}
			printf("\n");
			for(i=0;i<n;i++)
				printf("%f\t", a[i]);
	}
	else{
		printf("\"n\" must be even, please try again!\n\n");
		operate(n);
	}
}
