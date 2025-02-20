#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    
    long long ans = 0;
    for(int i=0;i<n/2;i++){
        ans -= v[i];
    }
    for(int i=n/2;i<n;i++){
        ans += v[i];
    }
    cout<<ans<<'\n';
    return 0;
}