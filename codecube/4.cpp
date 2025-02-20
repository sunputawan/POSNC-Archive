#include <bits/stdc++.h>

using namespace std;
long long gcd(long long a,long long b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
long long sum,d;
int main(){
    int n; cin>>n;
    while(n--){
        long long a; cin>>a;
        sum += a;
        d = gcd(d,a);
    }
    cout<<sum/d<<'\n';
}