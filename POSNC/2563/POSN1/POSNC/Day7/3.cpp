#include <stdio.h>
int day(int,int);
int main(){
	int d,m,y;
	scanf("%d", &m);
	scanf("%d", &y);
	d=day(m,y);
	printf("%d", d);
}
int day(int m,int y){
	switch(m){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			if(y%4==3)
				return 29;
			else
				return 28;
	}
}
