#include <stdio.h>
int m, n, no_student, no_subject;
float score, total, average;
int main(){
	printf("Please enter the number of student and the number of subject respectively : ");
	scanf("%d%d", &no_student, &no_subject);
	printf("\n");
	for(n=1; n<=no_student;n++ )
	{
		total=0;
		printf("student %d \n", n);
		for(m=1; m<=no_subject; m++)
		{
			printf("subject%d score:", m);
			scanf("%f", &score);
			total=total+score;
		}
		average = total/no_subject;
		printf("The average score of student%d is %f\n\n", n, average);
	}
}
