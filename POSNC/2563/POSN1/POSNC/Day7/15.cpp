#include <stdio.h>
int digit(int);
int reverse(int [],int,int);
void print(int[],int);
int main(){
	int n;
	scanf("%d", &n);
	int a[digit(n)];
	reverse(a,digit(n)-1,n);
	print(a,n);
}
int digit(int n){
	int count=0,i;
	for(i=0;n>0;i++){
		n/=10;
		count++;
	}
	return count;
}
int reverse(int a[],int i,int n){
		a[i]=n%10;
	if(i)
		return reverse(a,i-1,n/10);
	else
		return 0;
}
void print(int a[],int n){
	int i;
	for(i=digit(n)-1;i>=0;i--)
		printf("%d", a[i]);
}
