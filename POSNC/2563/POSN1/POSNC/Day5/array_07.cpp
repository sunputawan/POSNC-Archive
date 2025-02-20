#include <stdio.h>
int count =0;
int i,j;
int A[4],B[4];
int main(){
	for(i=0;i<4;i++){
		printf("Enter set A positive element%d : ", i+1);
		scanf("%d", &A[i]);
		if(A[i]<=0){
			printf("Invalid input!");
			return 0;
		}
		for(j=0;j<i;j++){
			if(A[j]==A[i])
				A[i]=0;
		}
	}
	printf("\n");
	for(i=0;i<4;i++){
		printf("Enter set B positive element%d : ", i+1);
		scanf("%d", &B[i]);
		if(B[i]<=0){
			printf("Invalid input!");
			return 0;
		}
		for(j=0;j<i;j++){
			if(B[j]==B[i])
				B[i]=0;
		}
	}
	for(i=0;i<4;i++){
		if(A[i]==0)
			continue;
		for(j=0;j<4;j++){
			if(B[j]==0)
				continue;
			if(B[j]==A[i])
				count ++;
		}
	}
	printf("There are %d element(s) which is(are) in set A and B.", count);
}
