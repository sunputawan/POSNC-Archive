#include <stdio.h> 
float home[100][5];
float mid[100];
float form[100];
float score[100];
int n,i,j;
float homework;
 
int main(){
	printf("How many student participate the test : ");
	scanf("%d", &n);
	if(n>100||n<0){
		printf("\"n\" must be positive and not more than 100, please try again!");
		return 0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<5;j++){
			printf("Enter student%d homework score%d (10): ", i+1,j+1);
			scanf("%f", &home[i][j]);
			if(home[i][j]<0||home[i][j]>10){
				printf("The score must be positive and not more than 10, please try agian!");
				return 0;
			}
		}
		printf("\n************************************\n\n");
	}
	for(i=0;i<n;i++){
		printf("Enter student%d midterm score (100): ", i+1);
		scanf("%f", &mid[i]);
		if(mid[i]<0||mid[i]>100){
			printf("The score must be positive and not more than 100, please try agian!");
			return 0;
		}
	}
	printf("\n************************************\n\n");
	for(i=0;i<n;i++){
		printf("Enter student%d formative score (100): ", i+1);
		scanf("%f", &form[i]);
		if(form[i]<0||form[i]>100){
			printf("The score must be positive and not more than 100, please try agian!");
			return 0;
		}
	}
	printf("\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<5;j++)
		{
			homework+=home[i][j];
		}
		score[i]= ((homework)*20/50 + (mid[i])*30/100 + (form[i])*50/100);
		printf("Student%d (100) : %f\n", i+1, score[i]);
		homework=0;
	}
}


