#include <stdio.h>
int main(){
	FILE *fp;
	fp=fopen("oddnumber.txt", "w");
	for(int i=1;i<100;i+=2){
		fprintf(fp,"%d\n", i);
	}
}
