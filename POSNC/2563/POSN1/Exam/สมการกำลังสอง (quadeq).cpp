#include<stdio.h>
#include <math.h>
void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
int main(){
	int A,B,C;
	int a,b,c,d,m=1;
	int s1,s2,s3,s4,s5;
	scanf("%d%d%d", &A,&B,&C);
	if(pow(B,2)-4*A*C<0||pow(B,2)-4*A*C!=pow(sqrt(pow(B,2)-4*A* C),2)){
		printf("No Solution");
		return 0;
	}
	for(int i=2;i<=A &&(i<=abs(B)||B==0)&&(i<=abs(C)||C==0);i++){
		if(A%i==0 && B%i==0 && C%i==0){
			m *= i;
			A /= i;
			B /= i;
			C /= i;
			i--;
		}
	}
	s1=-B;
	s2=sqrt(B*B-4*A*C);
	s3=2*A;
	s4=s1+s2;
	s5=s1-s2;
	for(int i=2;i<=s3&&(i<=abs(s4)||s4==0);i++){
		if(s3%i==0&&s4%i==0){
			s3/=i;
			s4/=i;
			i--;
		}
	}
	a=s3;
	b=-s4;
	s3=2*A;
	for(int i=2;i<=s3&&(i<=abs(s5)||s5==0);i++){
		if(s3%i==0&&s5%i==0){
			s3/=i;
			s5/=i;
			i--;
		}
	}
	c=s3;
	d=-s5;
	if(a>c){
		swap(&a,&c);
		swap(&b,&d);
	}
	else if(c==a){
		if(b>d){
			swap(&b,&d);
		}
	}
	c*=m;
	d*=m;
	printf("(%dx+%d)(%dx+%d)", a,b,c,d);
}
