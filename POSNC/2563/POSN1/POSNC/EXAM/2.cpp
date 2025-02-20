#include <stdio.h>
#include <string.h>
#include <math.h>
int check(char [],int);
int dec(char [],int);
char remain(int,int);
int main(){
	char a[20],b[20];
	char sum[21]={};
	int n,n1,n2,x,i;
	scanf("%d", &n);
	if(n<2||n>16){
		printf("Out of RANGE!");
		return 0;
	}
	printf("Num1 : ");
	scanf("%s", a);
	if(!(check(a,n))||strlen(a)>20){
		printf("Invalid input!");
		return 0;
	}
	printf("Num2 : ");
	scanf("%s", b);
	if(!(check(b,n))||strlen(b)>20){
		printf("Invalid input!");
		return 0;
	}
	n1=dec(a,n);
	n2=dec(b,n);
	x=n1+n2;
//	printf("%d  %d\n", n1,n2);
	for(i=0;x>0;i++){
		sum[i]=remain(x,n);
		x/=n;
	}
	for(i=strlen(sum)-1;i>=0;i--){
		printf("%c", sum[i]);
	}
}
int check(char a[],int n){
	int i;
	for(i=0;i<strlen(a);i++){
		if(n<11)
			if(a[i]-48>=n)
				return 0;
		if(n>=11)
			if(a[i]>54+n)
				return 0;
	}
	return 1;
}
int dec(char a[],int n){
	int i,j,result=0;
	for(i=0;i<strlen(a);i++){
		if(a[i]<=57)
			result+=((a[i]-48)*pow(n,strlen(a)-i-1));
		else
			result+=((a[i]-55)*pow(n,strlen(a)-i-1));
	}
	return result;
}
char remain(int x,int n){
	switch(x%n){
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		case 15:
			return 'F';
	}
}
