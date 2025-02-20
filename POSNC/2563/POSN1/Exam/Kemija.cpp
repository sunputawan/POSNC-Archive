#include <stdio.h>
#include <string.h>
int main(){
	int i;
	char a[100];
	gets(a);
	for(i=0;i<strlen(a);i++){
		switch(a[i]){
			case 'a':
				printf("a");
				i+=2;
				break;
			case 'e':
				printf("e");
				i+=2;
				break;
			case 'i':
				printf("i");
				i+=2;
				break;
			case 'o':
				printf("o");
				i+=2;
				break;
			case 'u':
				printf("u");
				i+=2;
				break;
			default:
				printf("%c", a[i]);
				break;
		}
	}
}
