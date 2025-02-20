#include <bits/stdc++.h>

using namespace std;
priority_queue<int> pq;
int a[1005][1005],ans;
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int state=2*n;state>=3;state--){
        for(int i=n,j=state-i;i>0&&j<=n;i--,j++){
            if(j>0) pq.push(a[i][j]);
        }
        ans += pq.top();
        pq.pop();
    }

    cout<<ans<<'\n';
    return 0;
}