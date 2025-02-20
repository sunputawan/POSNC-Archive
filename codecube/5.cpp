#include <bits/stdc++.h>

using namespace std;
long long gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
long long lcm(long long a,long long b){
    return a/gcd(a,b)*b;
}
int main(){
    int n; cin>>n;
    long long ans = 1;
    while(n--){
        long long a; cin>>a;
        ans = lcm(ans,a);
    }
    cout<<ans<<'\n';
}