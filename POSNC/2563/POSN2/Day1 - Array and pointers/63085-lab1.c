#include<stdio.h>
int main(){
    int a=5;
    double b=395202;
    char c='x';
    int *pa=&a;
    double *pb=&b;
    char *pc=&c;
    printf("Value of int is %d\n", a);
    printf("Address of int is %p\n", pa);
    printf("Size of of int is bytes %d\n",sizeof(a));
    printf("Size of of pointer to int is bytes %d\n\n", sizeof(pa));

    printf("Value of double is %d\n", b);
    printf("Address of double is %p\n", pb);
    printf("Size of of double is bytes %d\n",sizeof(b));
    printf("Size of of pointer to double is bytes %d\n\n", sizeof(pb));

    printf("Value of char is %c\n", c);
    printf("Address of char is %p\n", pc);
    printf("Size of of char is bytes %d\n",sizeof(c));
    printf("Size of of pointer to char is bytes %d\n\n", sizeof(pc));
}
