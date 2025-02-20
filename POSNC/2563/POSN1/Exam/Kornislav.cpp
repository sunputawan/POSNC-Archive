#include <stdio.h>
int s[4];
int i,j,t;
int main(){
	for(i=0;i<4;i++)
		scanf("%d", &s[i]);
	for(i=0;i<3;i++)
		for(j=i+1;j<4;j++)
			if(s[i]>s[j]){
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
	printf("%d", s[0]*s[2]);
}
