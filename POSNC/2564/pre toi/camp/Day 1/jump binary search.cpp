#include <bits/stdc++.h>

using namespace std;
vector<int> a;
int main(){
    int n,k,ans=0;
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        ans = max(ans,upper_bound(a.begin(),a.end(),a[i]+k)-a.begin()-i-1);
    }
    cout<<ans;
    return 0;
}
