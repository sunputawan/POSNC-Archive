#include <stdio.h>
int i;
void func(char []);
char text[15];
int main(){
	printf("Enter a word : ");
	scanf("%s", text);
	func(text);

}
void func(char array[15]){
		for(i=0;i<15;i++){
		if(array[i]=='\0')
			array[i-1]=' ';
	}
	for(i=0;i<15;i++)
		printf("%c", array[i]);
}
