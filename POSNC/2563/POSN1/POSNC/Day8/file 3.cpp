#include <stdio.h>
int main(){
	FILE *fp1,*fp2,*fp3;
	int a,b;
	fp1=fopen("C:\\Users\\acer\\Documents\\DEV\\POSNC\\Day8\\file1.txt", "r");
	fp2=fopen("C:\\Users\\acer\\Documents\\DEV\\POSNC\\Day8\\file2.txt", "r");
	fp3=fopen("C:\\Users\\acer\\Documents\\DEV\\POSNC\\Day8\\file3.txt", "w");
	for(int i=0;i<10;i++){
		fscanf(fp1,"%d", &a);
		fscanf(fp2,"%d", &b);
		fprintf(fp3,"%d\n", a+b);
	}
	fclose(fp1),fclose(fp2),fclose(fp3);
}
