#include <iostream>
using namespace std;


int F[100];
int fib(int n){
    F[0]=0; F[1]=1;
    for(int i=2;i<=n;i++)
        F[n]=F[n-1]+F[n-2];
    return F[n];
}
int main(){
    int n;
    cin>>n;
    fill(F,F+100,-1);
    cout<<fib(n);
}
