#include <stdio.h>
void generate(int,char,int);
int main(){
	int i,j,di,size;
	scanf("%d",&di);
	if(di!=1&&di!=2){
		printf("Out of range!");
		return 0;
	}
	scanf("%d", &size);
	if(di==1){
		generate(size,'/',1);
		generate(size,'\\',2);
	}
	if(di==2){
		generate(size,'\\',2);
		generate(size,'/',1);
	}
}
void generate(int size,char a,int d){
	int i,j;
	if(d==1){
		for(i=0;i<size;i++){
			for(j=0;j<size-1-i;j++)
				printf(" ");
			printf("%c\n\n", a);
		}
	}
	if(d==2){
		for(i=0;i<size;i++){
			for(j=0;j<i;j++)
				printf(" ");
			printf("%c\n\n", a);
		}
	}
}
