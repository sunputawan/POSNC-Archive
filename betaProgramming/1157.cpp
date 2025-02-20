#include <bits/stdc++.h>

using namespace std;
int main(){
    int n,k; cin>>n>>k;
    deque<pair<int,int>> dq;
    int x; cin>>x;
    dq.push_back({x,1});
    int cost;
    for(int i=2;i<=n;i++){
        cin>>x;
        while(!dq.empty() && i-dq.front().second>k)
            dq.pop_front();
        cost = x + dq.front().first;
        while(!dq.empty() && dq.back().first>cost)
            dq.pop_back();
        dq.push_back({cost,i});
    }

    cout<<cost<<'\n';

    return 0;
}