#include <stdio.h>
int score;
char grade;
int main(){
	printf("Please input score : ");
	scanf("%d", &score);
	switch(score/10){
		case 10 :
		case 9 :
		case 8 :
			grade='A';
			printf("Grade : %c", grade);
			break;
		case 7:
		case 6:
			grade='B';
			printf("Grade : %c", grade);
			break;
		case 5:
		case 4:
			grade='C';
			printf("Grade : %c", grade);
			break;
		case 3:
		case 2:
		case 1:
		case 0:
			grade='D';
			printf("Grade : %c", grade);
			break;
		default :
			printf("Invalid input!");			
	}
}
