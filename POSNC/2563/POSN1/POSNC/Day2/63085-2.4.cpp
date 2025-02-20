#include<stdio.h>
int mid,fin;
int main(){
	printf("Please enter midterm score : ");
	scanf("%d", &mid);
	if(mid>100||mid<0)
		printf("Invalid input!!");
	else
	{
		printf("Please enter final score : ");
		scanf("%d", &fin);
		if(fin>100||fin<0)
			printf("Invalid input!!");
		else
		{
			switch((mid+fin)/20){
				case 10:
				case 9:
				case 8:
					printf("Your Score = %d %%\nGrade = G,Good", (mid+fin)/2);
					break;
				case 7:
				case 6:
				case 5:
					printf("Your Score = %d %%\nGrade = P,Pass", (mid+fin)/2);
					break;
				case 4:
				case 3:
				case 2:
				case 1:
				case 0:
					printf("Your Score = %d %%\nGrade = F,Fail", (mid+fin)/2);
					break;
			}
		}
	}

}
