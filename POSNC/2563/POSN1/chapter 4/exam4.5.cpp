#include <stdio.h>
void input_score(int,int);
char grade_score(int,int);
int m,n,i,j,k;
char grade;
char GRADE[100];
int main(){
	printf("How many students parcipitate the test : ");
	scanf("%d", &n);
	if(n>100 || n<0)
		printf("The number of student must not be positive and more than 100, please run the program again!");
	else{
		input_score(0,n);
		printf("\n\n***************************************\n\n\n");
		for(m=0;m<n;m++){
			printf("\tStudent%d : %c\n", m+1, GRADE[m]);
		}
		printf("\n");
	}
}
void input_score(int j,int n){
	int SCORE[n];
	for(i=j;i<n;i++){
		printf("Enter student%d score : ", i+1);
		scanf("%d", &SCORE[i]);
		if(SCORE[i]>100 || SCORE[i]<0){
			printf("The score must be a positive integer not more than 100, please try again!\n");
			input_score(i,n);
		}
		else
			GRADE[i] = grade_score(SCORE[i],i);
	}
}
char grade_score(int k,int i){
	if(k>=90)
		grade = 'A';
	else	if(k>=80&&k<90)
				grade = 'B';
			else	if(k>=70&&k<80)
						grade = 'C';
					else	if(k>=60&&k<70)
							grade = 'D';
							else	if(k>=50&&k<60)
										grade = 'E';
									else
										grade = 'F';
	return grade;
}
