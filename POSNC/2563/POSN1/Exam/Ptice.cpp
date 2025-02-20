#include <stdio.h>
int main(){
	int n,i,max;
	scanf("%d", &n);
	int counta=0,countb=0,countg=0;
	char a[n],b[n],g[n],s[n];
	scanf("%s",s);
	printf("\n");
	for(i=0;i<n;i++){
		switch(i%3){
			case 0:
				a[i]='A';
				break;
			case 1:
				a[i]='B';
				break;
			case 2:
				a[i]='C';
				break;
		}
		switch(i%4){
			case 0:
				b[i]='B';
				break;
			case 1:
				b[i]='A';
				break;
			case 2:
				b[i]='B';
				break;
			case 3:
				b[i]='C';
				break;
		}
		switch(i%6){
			case 0:
			case 1:
				g[i]='C';
				break;
			case 2:
			case 3:
				g[i]='A';
				break;
			case 4:
			case 5:
				g[i]='B';
				break;
		}
		if(s[i]==a[i])
			counta++;
		if(s[i]==b[i])
			countb++;
		if(s[i]==g[i])
			countg++;
	}
//	printf("%s\n%s\n%s", a,b,g);
//	printf("%d %d %d\n", counta,countb,countg);
	if(counta>countb)
		max=counta;
	else
		max=countb;
	if(countg>max)
		max=countg;
	printf("%d\n", max);
	if(counta==max)
		printf("Adrian\n");
	if(countb==max)
		printf("Bruno\n");
	if(countg==max)
		printf("Goran\n");
}
