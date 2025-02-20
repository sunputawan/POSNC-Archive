#include <stdio.h>
int weight,piece,tax_rate;
int main(){
	printf("Enter total weight (kg) : ");
	scanf("%d",&weight);
	if(weight<0)
		printf("Invalid input,please try again!");
	else
	{
		printf("Enter number of pieces : ");
		scanf("%d", &piece);
		if(piece<0)
			printf("Invalid input,please try again!");
		else{
			if(weight>10000)
				tax_rate=10000;
			else	if(weight>2000)
						tax_rate=3000;
					else	if(weight>100)
								tax_rate=1000;
							else	if(weight>20)
										tax_rate=500;
									else
										tax_rate=200;
			printf("There are %d piece(s) and tax value cost %d a piece.\nThe total TaxValue is %d. ", piece, tax_rate, piece*tax_rate);	
		}
	}
}
