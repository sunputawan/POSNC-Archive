#include <stdio.h>
int main(){
	int t,l,w,i,j;
	printf("Enter tile width : ");
	scanf("%d", &t);
	printf("Enter Lenght : ");
	scanf("%d", &l);
	printf("Enter Width : ");
	scanf("%d", &w);
	i=i%26;
	int counti=0;
	for(i=0;counti!=w;i++){
		if(i==25)
			i=-1;
		int countj =0;
		for(j=i;countj!=l;j++){
			printf("%c", 65+j);
			if(j==25)
				j=-1;
			countj++;
		}
		printf("\n");
		counti++;
	}
}
