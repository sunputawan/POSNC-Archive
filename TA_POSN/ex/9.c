#include <stdio.h>
#include <math.h>

// c*c = a*a + b*b
 // a =sqrt(c*c-b*b)
int main(void){
    double a,b,c; scanf("%lf %lf %lf",&a,&b,&c);
    if(a==0){
        double x = sqrt(c*c-b*b);
        printf("%.2lf\n",x);
    }
    else if(b==0){
        double x = sqrt(c*c-a*a);
        printf("%.2lf\n",x);
    }
    else{
        double x = sqrt(a*a+b*b);
        printf("%.2lf\n",x);
    }

    return 0;
}