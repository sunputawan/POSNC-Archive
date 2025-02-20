#include <stdio.h>
int data[5][5];
int branch,department,total;
int i,j;
int main(){
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("Enter branch%d department%d income : ", i+1,j+1);
			scanf("%d", &data[i][j]);
		}
		printf("\n\n");
	}
	printf("*******************************\n\n");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			branch+=data[i][j];
		}
		printf("Branch%d : %d \n", i+1,branch);
		branch=0;
	}
	printf("\n*******************************\n\n");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			department+=data[j][i];
		}
		printf("Department%d : %d \n", i+1,department);
		department=0;
	}
	printf("\n**************************************************************************************************************\n\n");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++)
			total+=data[i][j];
	}
	printf("\t\t\tThe total income of this department store : %d \n",total);
}
