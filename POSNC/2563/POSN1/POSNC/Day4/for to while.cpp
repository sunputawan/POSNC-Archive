#include <stdio.h>
int main(){
	int k=0;
	int m=10;
	while(k<10||m<50){
		printf("%d ", k);
		printf("%d\n", m);
		k+=2;
		m*=2;
	}
}
