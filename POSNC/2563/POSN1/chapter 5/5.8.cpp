#include <stdio.h>
int i;
void func(char []);
char text[15];
int main(){
	printf("Enter a word : ");
	scanf("%s", text);
	func(text);

}
void func(char array[]){
			array[0]=' ';
	for(i=0;i<15;i++){
		array[i]=array[i+1];
		printf("%c", array[i]);
	}
}
