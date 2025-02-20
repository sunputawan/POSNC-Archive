#include<stdio.h>
int n,no_personnel;
float sales, rate_commission, total_commission;
int main(){
	printf("Please input the number of personnel : ");
	scanf("%d", &no_personnel);
	for(n=1;n<=no_personnel;n++)
	{
		printf("\npersonnel%d\'s sales(Baht): ");
		scanf("%f", &sales);
		printf("\n");
		if(sales<0)
		{
			printf("ERROR!, The sales must not be less than 0.\nPlease run the program again!");
			break;
		}
		else	if(sales<10000)
					rate_commission=0;
			
				else	if(sales<25000)
							rate_commission=7;
						else
							rate_commission=10;

		total_commission = sales * (1 + rate_commission / 100);
		printf("No.\tTotal Sales(Baht)\tSales Commission(Baht)\n");
		printf(" %d\t%.2f  \t\t%.2f\n", n, sales, total_commission);
	}
}
