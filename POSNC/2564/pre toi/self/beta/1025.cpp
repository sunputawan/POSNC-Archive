#include <bits/stdc++.h>

using namespace std;
long long gcd(long long x,long long y){
    if(x==0)
        return y;

    return gcd(y%x,x);
}
long long lcm(long long x,long long y){
    return (x/gcd(x,y))*y;
}
int main(){
    int n; cin>>n;
    long long ans = 1;
    for(int i=0;i<n;i++){
        long long x; cin>>x;
        ans = lcm(ans,x);
    }
    cout<<ans;
    return 0;
}
