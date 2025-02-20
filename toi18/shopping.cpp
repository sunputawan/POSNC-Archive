#include <bits/stdc++.h>

using namespace std;
long long cost[500005],point[500005];
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        if(a<0) cost[i] = -a;
        else point[i] = a;
    }

    for(int i=1;i<n;i++){
        cost[i] += cost[i-1];
        point[i] += point[i-1];
    }


    for(int i=0;i<n;i++) cout<<cost[i]<<' '; cout<<'\n';
    for(int i=0;i<n;i++) cout<<point[i]<<' ';

    while(m--){
        long long st,bud;
        cin>>st>>bud;
        int idx = lower_bound(cost,cost+n,bud+cost[st-1])-cost;
        cout<<idx<<'\n';
        //cout<<point[idx]-point[st-1]<<'\n';
    }
}

/*
8 6
-10 -3 5 6 -20 3 4 0
0 3
0 13
0 14
2 1
2 50000000
6 1
*/