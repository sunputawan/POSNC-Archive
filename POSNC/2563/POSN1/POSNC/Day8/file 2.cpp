#include <stdio.h>
int main(){
	FILE *fp;
	int a;
	fp=fopen("C:\\Users\\acer\\Documents\\DEV\\POSNC\\Day8\\file2.txt", "w");
	for(int i=0;i<10;i++){
		scanf("%d", &a);
		fprintf(fp,"%d ", a);
	}
	fclose(fp);
}
