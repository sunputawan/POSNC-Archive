#include <stdio.h>
int dy=0;
int main(){
	int d,m;
	scanf("%d%d", &d,&m);
	for(int i=1;i<m;i++){
		switch(i){
			case 4:
			case 6:
			case 9:
			case 11:
				dy+=30;
				break;
			case 2:
				dy+=28;
				break;
			default :
				dy+=31;
				break;
		}
	}
	dy+=d;
	switch(dy%7){
		case 1:
			printf("Thursday");
			break;
		case 2:
			printf("Friday");
			break;
		case 3:
			printf("Saturday");
			break;
		case 4:
			printf("Sunday");
			break;
		case 5:
			printf("Monday");
			break;
		case 6:
			printf("Tuesday");
			break;
		case 0:
			printf("Wenesday");
			break;
	}

	
}
