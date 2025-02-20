#include <stdio.h>
int best=1000000000;
void find(int,int,int);
int diff(int,int);
int n;
int s[10],b[10];
int main(){
	int j;
	scanf("%d", &n);
	for(j=0;j<n;j++)
		scanf("%d%d", &s[j],&b[j]);
	find(0,1,0);
	printf("%d",best);
}
void find(int i,int S,int B){
	if(i==n){
		if(B>0&&diff(S,B)<best)
			best=diff(S,B);
	}
	else{
		find(i+1,S,B);
		find(i+1,S*s[i],B+b[i]);
	}
			
}

int diff(int x,int y){
	if(x>y)
		return x-y;
	else
		 return y-x;
}
