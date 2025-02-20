#include <stdio.h>
int count=1,n;
int main(){
	while(count<=100){
		n = count*(count+1)/2;
		printf("%d\t", n);
		count++;
	}
}
