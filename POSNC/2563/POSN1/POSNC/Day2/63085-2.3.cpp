#include <stdio.h>
int user,sal,OT,total;
int main(){
	printf("username(xxxxx) : ");
	scanf("%d", &user);
	printf("Enter your salary and OT wage (salary-OT): ");
	scanf("%d%*c%d", &sal,&OT);
	total = sal + OT;
	if(total>=100000)
		printf("\nI.D. : %d\nYour bonus is at 10%%.", user);
	else	if(total>=70000)
				printf("\nI.D. : %d\nYour bonus is at 7%%.", user);
			else	if(total>=50000)
						printf("\nI.D. : %d\nYour bonus is at 5%%.", user);
					else	if(total>=30000)
								printf("\nI.D. : %d\nYour bonus is at 3%%.", user);
							else
								printf("\nI.D. : %d\nYour bonus is at 1%%.", user);
}
