#include <stdio.h>
int i,j,k,n,r,count=0;
int remainder[42];
int main(){
	printf("Please input 10 integer seperately : \n");
	for(j=0;j<42;j++);
	remainder[j]=0;
	for(i=1;i<=10;i++){
		scanf("%d", &n);
		r = n%42;
		remainder[r]=1;
	}
	for(k=0;k<42;k++){
		if(remainder[k]==1){
			count++;
		}	
	}
	printf("ÁÕàÈÉ·Ñé§ËÁ´ %d áºº", count);
}
