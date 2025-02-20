#include <bits/stdc++.h>

using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        pq.push({a,1});
        pq.push({b,-1});
    }

    int num = 0;
    int maxnum = 0;
    while(!pq.empty()){
        num+=pq.top().second;
        pq.pop();
        maxnum = max(maxnum,num);
    }
    cout<<maxnum;
    return 0;
}
