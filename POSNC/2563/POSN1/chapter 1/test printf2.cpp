#include <stdio.h>
int main(){
	printf("%10s%10d%10c\n", "good", 3 ,'x');
	printf("%-10s%-10d%-10c\n", "good", 3 ,'x');
	printf("%010s%010d%010c\n", "good", 3 ,'x');
	printf("%-010s%-010d%-010c\n", "good", 3 ,'x');
}
