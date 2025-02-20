#include <iostream>

using namespace std;
typedef long long unsigned llu;
llu fibonacci(int n,llu *fib){
    if(n==0||n==1)
        fib[n] = n;
    if(fib[n]==-1)
        fib[n] = fibonacci(n-1,fib)+fibonacci(n-2,fib);
    return fib[n];
}
int main(){
    int n; cin>>n;
    llu fib[n+1]={};
    for(int i=0;i<=n;i++)
        fib[i]=-1;
    fibonacci(n,fib);
    for(int i=1;i<=n;i++)
        cout<<fib[i]<<" ";
}
