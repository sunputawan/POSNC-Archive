#include <stdio.h>
int main( )
{
    char c = 'Z';
    char *cp = &c;
    printf("cp is %p\n", cp);
    printf("The character at cp is %c\n",*cp);
    cp = cp+1;
    printf("cp is %p\n\n", cp);

    int a=5;
    int *intp= &a;
    printf("intp is %p\n", intp);
    printf("The int at intp is %d\n",intp);
    intp = intp+1;
    printf("intp is %p\n\n", intp);

    double d=322654;
    double *dbp= &d;
    printf("dbp is %p\n", dbp);
    printf("The double at dbp is %f\n",*dbp);
    dbp = dbp+1;
    printf("dbp is %p\n\n", dbp);

return 0;
}
