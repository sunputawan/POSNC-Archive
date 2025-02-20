#include <stdio.h>
int digit(int);
int main(){
	int n,m,i,j;
	int count[10]={};
	printf("Enter n,m respectively: ");
	scanf("%d %d", &n,&m);
	for(i=n;i<=m;i++){
		int k=i;
		for(j=0;j<digit(i);j++){
			switch(k%10){
				case 0:
					count[0]++;
					break;
				case 1:
					count[1]++;
					break;
				case 2:
					count[2]++;
					break;
				case 3:
					count[3]++;
					break;
				case 4:
					count[4]++;
					break;
				case 5:
					count[5]++;
					break;
				case 6:
					count[6]++;
					break;
				case 7:
					count[7]++;
					break;
				case 8:
					count[8]++;
					break;
				case 9:
					count[9]++;
					break;
			}
			k/=10;
		}
	}
	for(i=0;i<10;i++){
		printf("%d : %d\n", i,count[i]);
	}
}
int digit(int n){
	int count=0;
	for(int i=0;n>0;i++){
		n/=10;
		count++;
	}
	return count;
}
