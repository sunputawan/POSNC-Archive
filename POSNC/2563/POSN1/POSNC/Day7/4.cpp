#include <stdio.h>
int lcm(int,int);
int gcd(int,int);
int main(){
	int i,n,l=1,g=1;
	scanf("%d", &n);
	int data[n];
	for(i=0;i<n;i++)
		scanf("%d", &data[i]);
	l=lcm(data[0],data[1]);
	g=gcd(data[0],data[1]);
	if(n>2){
		for(i=2;i<n;i++){
			l=lcm(l,data[i]);
		}
	}
	if(n>2){
		for(i=2;i<n;i++){
			g=gcd(g,data[i]);
		}
	}
	printf("lcm = %d\n", l);
	printf("gcd = %d", g);
	return 0;
}
int lcm(int a,int b){
	int i,l=1;
	for(i=2;i<=a||i<=b;i++){
		if(a%i==0&&b%i==0){
			a/=i;
			b/=i;
			l*=i;
		}
	}
	l*=a*b;
	return l;
}
int gcd(int a,int b){
	int i,l=1;
	for(i=2;i<=a||i<=b;i++){
		if(a%i==0&&b%i==0){
			a/=i;
			b/=i;
			l*=i;
		}
	}
	return l;
}
