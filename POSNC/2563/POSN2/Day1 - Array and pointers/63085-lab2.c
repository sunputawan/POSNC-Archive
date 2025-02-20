#include <stdio.h>
void foo1(int xval)
{
int x;
x = xval;
printf("\nAddress of x is %p and Value of x is %d\n", &x,x);
printf("Address of xval is %p and Value of xval is %d\n", &xval,xval);
}
void foo2(int dummy)
{
int y;
printf("\nAddress of y is %p and Value of y is %d\n", &y,y);
printf("Address of dummy is %p and Value of dummy is %d\n", &dummy,dummy);
}
int main() {
foo1(7);
foo2(11);
return 0;
}
