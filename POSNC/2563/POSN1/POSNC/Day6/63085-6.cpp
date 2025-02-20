#include <stdio.h>
#include <string.h>
int countnum=0,countcon=0,countvow=0;
char text[50];
int i;
int main(){
	printf("Enter text : ");
	scanf("%s", text);
	for(i=0;i<strlen(text);i++){
		if(text[i]<=57&&text[i]>=48)
			countnum++;
		else if(text[i]=='a'||text[i]=='e'||text[i]=='i'||text[i]=='o'||text[i]=='u'||text[i]=='A'||text[i]=='E'||text[i]=='I'||text[i]=='O'||text[i]=='U')
			countvow++;
		else if((65<=text[i]&&text[i]<=90)||(97<=text[i]&&text[i]<=122))
			countcon++;
	}
	printf("Number : %d\nConsonant : %d\nVowel : %d", countnum,countcon,countvow);
}
