#include <stdio.h>
#include <string.h>
int i,len;
char str[10];
int main(){
	printf("Enter string : ");
	scanf("%s", str);
	len=strlen(str);
	for(i=0;i<len;i++){
		printf("%c : %d\n", str[i],str[i]);
		if(str[i]<65||(str[i]>90&&str[i]<97)||str[i]>122){
			printf("Invalid input!");
			return 0;
		}
		if(str[i]<=90)
			str[i]+=32;
		else
			str[i]-=32;
	}
	printf("%s", str);
}
