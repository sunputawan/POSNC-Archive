#include <iostream>
long long f[100];
int s(int n){
    f[0]=2,f[1]=3;
    for(int i=2;i<n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}
using namespace std;
int main(){
    int n;
    cin>>n;
    s(n);
    cout<<f[n-1];
}
