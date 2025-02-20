#include <stdio.h>
char a[19];
char b[16]={};
int c[16];
int i,j=15;
int sum=0;
int main(){
	printf("Enter card (xxxx-xxxx-xxxx-xxxx) : ");
	scanf("%s", a);
	for(i=0;i<19;i++){
		if(a[i]=='-')
			continue;
		else{
			b[j]=a[i];
			j--;
		}
	}
	printf("%s\n", b);
	for(i=0;i<16;i++){
		switch(b[i]){
			case '1':
				c[i]=1;
				break;
			case '2':
				c[i]=2;
				break;
			case '3':
				c[i]=3;
				break;
			case '4':
				c[i]=4;
				break;
			case '5':
				c[i]=5;
				break;
			case '6':
				c[i]=6;
				break;
			case '7':
				c[i]=7;
				break;
			case '8':
				c[i]=8;
				break;
			case '9':
				c[i]=9;
				break;
			case '0':
				c[i]=0;
				break;
		}
	}
	for(i=0;i<16;i++){
		if(i%2==0){
			c[i]*=2;
			if(c[i]>=10)
				c[i]-=9;
		}
		sum+=c[i];
	}
	if(sum%10==0)
		printf("It\'s real card.");
	else
		printf("It\'s fake card.");
}
