#include <stdio.h>
#include <string.h>
char name[30];
char sur[15];
int gender;
int main(){
	printf("Enter name : ");
	scanf("%s", name);
	printf("Enter surname : ");
	scanf("%s", sur);
	printf("Male=1,Female=2 : ");
	scanf("%d", &gender);
	name[strlen(name)]=' ';
	strcat(name,sur);
	switch(gender){
		case 1:
			printf("Mr.%s",name);
			break;
		case 2:
			printf("Mrs.%s",name);
			break;
	}
}
