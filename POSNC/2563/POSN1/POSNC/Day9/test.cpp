#include <stdio.h>
int main(){

int  a,b;
int *p;
p=&a;
*p=1;
a=5;
p=&b;
b=60;
*p=a;
printf("%d, %d", a,b);
}
