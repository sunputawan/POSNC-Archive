#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[2005];
int main(){
    ll n; cin>>n;
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }

    sort(a,a+2*n);

    ll ans = 0;
    for(int i=0;i<n;i++){
        //cout<<v[i]<<" "<<v[2*n-1-i]<<endl;
        ans += a[i]*a[2*n-1-i];
    }
    cout<<ans;
    return 0;
}
