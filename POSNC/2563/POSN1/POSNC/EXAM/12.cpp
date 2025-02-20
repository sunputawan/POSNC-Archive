#include <stdio.h>
#include <string.h>

int main(){
	int n,i,j=0,k,length,l,sum;
	char s[100]={};
	int a[100]={};
	printf("Enter number : ");
	scanf("%s", s);
	for(i=0;i<strlen(s);i++){
		if(s[i]=='0'){
			j++;
		}
		else if('1'<=s[i]&&s[i]<='9'){
			a[j] += s[i]-'0';
		}
		else{
			printf("error\n");
			return 0;
		}
		if(i<strlen(s)-1)
			a[j]*=10;
	}
	for(i=0;i<j;i++){
		int count=0,t=1;
		for(k=0;k<i;k++){
			if(a[k]==a[i])
				t=0;
		}
		if(t){
			for(k=i;k<j;k++)
				if(a[i]==a[k])
					count++;
			printf("%d\t%d\n", a[i],count);
		}
	}
}
