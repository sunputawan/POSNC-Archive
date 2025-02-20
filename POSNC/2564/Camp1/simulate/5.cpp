#include <iostream>

using namespace std;
typedef long long unsigned llu;
int main(){
    llu fib[502]={};
    int n;
    cin>>n;
    fib[0]=0;
    fib[1]=1;
    for(int i=1;i<=n;i++){
        fib[i+1] = fib[i]+fib[i-1];
    }
    cout<<fib[n-2]<<endl<<fib[n-1]<<endl<<fib[n];
}
