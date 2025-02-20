#include<stdio.h>
char str[50];
int t,i;
char str2[]= "123";
int main(){
	scanf("%s", str);
	for(i=0;i<50;i++)
	{
		if(str[i]=='A')
			{
				t=str2[0];
				str2[0]=str2[1];
				str2[1]=t;
			}
		else	if(str[i]=='B')
				{
					t=str2[1];
					str2[1]=str2[2];
					str2[2]=t;
				}
		else	if(str[i]=='C')
				{
					t=str2[2];
					str2[2]=str2[0];
					str2[0]=t;
				}
	}
	for(i=0;i<3;i++)
	{
		if(str2[i]=='1')
			printf("%d", i+1);
 	}
}
