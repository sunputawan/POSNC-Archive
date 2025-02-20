#include <stdio.h>
#include <string.h>
char str[50];
int i,t;
int counta=0, counte=0, counti=0, counto=0, countu=0;
int main(){
	printf("%-17s==> ", "Input String");
	scanf("%s", str);
	printf("%-17s==> %d characters", "Length of String",strlen(str));
	printf("\n%-17s==> ", "Reverse String");
	for(i=strlen(str)-1;i>=0;i--)
		printf("%c",str[i]);
	printf("\n%-17s==> ", "Upper String");
	for(i=0;i<strlen(str);i++){
		if(str[i]>=97)
			str[i]=str[i]-32;
		printf("%c", str[i]);
	}
	printf("\n=-=-=-=-=-=-=-=-=-=\nNumber of vowel\n=-=-=-=-=-=-=-=-=-=\n");
	for(i=0;i<strlen(str);i++){
		switch(str[i]){
			case 'A':
			case 'a':
				counta++;
				break;
			case 'E':
			case 'e':
				counte++;
				break;
			case 'I':
			case 'i':
				counti++;
				break;
			case 'O':
			case 'o':
				counto++;
				break;
			case 'U':
			case 'u':
				countu++;
				break;
		}
	}
	printf("A or a= %d\n", counta);
	printf("E or e= %d\n", counte);
	printf("I or i= %d\n", counti);
	printf("O or o= %d\n", counto);
	printf("U or u= %d\n", countu);
	printf("=-=-=-=-=-=-=-=-=-=\n");
}
