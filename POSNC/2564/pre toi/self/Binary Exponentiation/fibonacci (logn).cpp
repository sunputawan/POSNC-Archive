#include <iostream>
#define N 100

using namespace std;
typedef unsigned long long ull;

/*
                            n
    Fn+1 Fn          1   1
                =
    Fn   Fn-1        1   0

*/

void multiply(ull a[2][2],ull b[2][2]){
    ull ans[2][2];
    ull w = a[0][0]*b[0][0]+a[0][1]*b[1][0];
    ull x = a[0][0]*b[0][1]+a[0][1]*b[1][1];
    ull y = a[1][0]*b[0][0]+a[1][1]*b[1][0];
    ull z = a[1][0]*b[0][1]+a[1][1]*b[1][1];

    a[0][0] = w;
    a[0][1] = x;
    a[1][0] = y;
    a[1][1] = z;

    return;
}
void power(ull F[2][2],int n){
    if(n==0||n==1)
        return;
    ull remain[2][2] = {{1,1},{1,0}};
    power(F,n/2);
    multiply(F,F);
    if(n&1)
        multiply(F,remain);
}
ull fib(int n){
    ull F[2][2] = {{1,1},{1,0}};
    if(n==0)
        return 0;
    power(F,n-1);
    return F[0][0];
}
int main(){
    for(int i=0;i<N;i++)
        cout<<fib(i)<<'\n';
}
