#include <bits/stdc++.h>

using namespace std;

int qsum[100005];
int main(){
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        qsum[i] = x+qsum[i-1];
    }
    for(int i=n-1;i>=0;i--){
        qsum[i] = min(qsum[i],qsum[i+1]);
    }
    while(q--){
        int k; cin>>k;
        cout<<upper_bound(qsum,qsum+n+1,k)-qsum-1<<'\n';
    }
    return 0;
}
