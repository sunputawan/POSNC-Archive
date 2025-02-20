#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
int main(){
    long long a,b;
    cin>>a>>b;
    cout<<a/gcd(a,b)*b<<'\n';
}