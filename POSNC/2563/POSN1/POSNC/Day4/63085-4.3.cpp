#include <stdio.h>
float total;
int n,r,i;
int main(){
	printf("The deposit per year : " );
	scanf("%d", &n);
	printf("The interest per year(%) : ");
	scanf("%d", &r);
	for(i=1;i<=10;i++){
		total= (total+n)*(1+r/100.0);
	}
	printf("Total money after 10 years : %f", total);
}
