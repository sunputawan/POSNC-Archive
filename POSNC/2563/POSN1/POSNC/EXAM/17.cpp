#include <stdio.h>
int main(){
	int n,i,j,countn=0,countalp=0;
	scanf("%d", &n);
	for(i=1;countn!=n;i++){
		for(j=1;j<=i&&countn!=n;j++){
			printf("%c", 65+countalp);
			if(countalp==25)
				countalp=-1;
			countalp++;
			countn++;
		}
		printf("\n");
	}
}
