#include <stdio.h>
int binary(int);
int octal(int);
int hexadecimal(int);
int main(){
	int n;
	scanf("%d", &n);
	binary(n);
	printf("\n");
	octal(n);
	printf("\n");
	hexadecimal(n);
}
int binary(int n){
	int bin[n],count=0,i;
	for(i=0;n>0;i++){
		bin[i]=n%2;
		n/=2;
		count++;
	}
	for(i=count-1;i>=0;i--)
		printf("%d", bin[i]);
}
int octal(int n){
	int oct[n],count=0,i;
	for(i=0;n>0;i++){
		oct[i]=n%8;
		n/=8;
		count++;
	}
	for(i=count-1;i>=0;i--)
		printf("%d", oct[i]);
}
int hexadecimal(int n){
	int hex[n],count=0,i;
	for(i=0;n>0;i++){
		hex[i]=n%16;
		n/=16;
		count++;
	}
	for(i=count-1;i>=0;i--)
		switch(hex[i]){
			case 10:
				printf("A");
				break;
			case 11:
				printf("B");
				break;
			case 12:
				printf("C");
				break;
			case 13:
				printf("D");
				break;
			case 14:
				printf("E");
				break;
			case 15:
				printf("F");
				break;
			default :			
				printf("%d", hex[i]);
	}
}
