#include <stdio.h>
void swap(char *x,char *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int main(){
	int n;
	scanf("%d", &n);
	char a[n];
	scanf("%s", a);
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				swap(&a[i],&a[j]);
			}
		}
	}
	for(i=0;i<n;i++){
		if(a[i]=='0')
			continue;
		else{
			swap(&a[0],&a[i]);
			break;
		}
	}
	printf("%s", a);
}
