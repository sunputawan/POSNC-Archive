#include <stdio.h>
float inch;
float foot(float);
float cent(float);
float yard(float);
int main(){
	printf("Please enter lenght(inch) : ");
	scanf("%f", &inch);
	printf("foot : %f\ncentimetre : %f\nyard : %f", foot(inch), cent(inch), yard(inch));
}
float foot(float inch){
	return (inch/12);
}
float cent(float inch){
	return (2.54*inch);
}
float yard(float inch){
	return (inch/36);
}
