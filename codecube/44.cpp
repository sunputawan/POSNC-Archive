#include <bits/stdc++.h>

using namespace std;
int n,h[1000005],len[1000005];
priority_queue<pair<int,int>> pq;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        pq.push({h[i],i});
    }
    
    while(!pq.empty()){
        int idx = pq.top().second;
        len[idx] = pq.size();
        pq.pop();
    }
    for(int i=1;i<=n;i++){
        cout<<len[i]<<' ';
    }
    return 0;
}