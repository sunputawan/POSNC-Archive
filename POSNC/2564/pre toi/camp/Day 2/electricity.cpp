#include <bits/stdc++.h>

using namespace std;
int a[500005];
int ans[500005];
set<pair<int,int>> s;
int main(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    s.insert({a[1],1});
    ans[1] = a[1];
    for(int i=2;i<=k;i++){
        ans[i] = a[i]+a[1];
        s.insert({ans[i],i});
    }
    for(int i=k+1;i<=n;i++){
        ans[i]=a[i]+s.begin()->first;
        s.erase({ans[i-k],i-k});
        s.insert({ans[i],i});
    }
    cout<<ans[n];
    return 0;
}
