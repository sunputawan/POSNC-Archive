#include <stdio.h>
int check(char);
int main(){
	char w;
	scanf("%c", &w);
	if(check(w))
		printf("yes");
	else
		printf("no");
}
int check(char w){
	switch(w){
		case 'Y':
		case 'y':
		case 'N':
		case 'n':
			return 1;
		default :
			return 0;
	}
}
