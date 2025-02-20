#include <bits/stdc++.h>

using namespace std;
int a[105][10005];
int dp[105][10005];
int mx = 0;
int main(){
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    deque<pair<int,int>> dq;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k+1;j++){
            while(!dq.empty() && dq.back().first<=a[i-1][j])
                dq.pop_back();
            dq.push_back({a[i-1][j],j});
        }
        for(int j=1;j<=m;j++){
            while(!dq.empty() && j-dq.front().second>k) dq.pop_front();
            a[i][j] += dq.front().first;
            if(i==n)
                mx = max(mx,a[i][j]);
            if(j+k+1<=m){
                while(!dq.empty() && dq.back().first<=a[i-1][j+k+1])
                    dq.pop_back();
                dq.push_back({a[i-1][j+k+1],j+k+1});
            }
        }
        dq.clear();
    }
    cout<<mx<<'\n';

    return 0;
}