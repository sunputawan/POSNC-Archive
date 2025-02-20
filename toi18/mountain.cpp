#include <bits/stdc++.h>

using namespace std;
struct point{
    long long x,y;
}node[505];
long long dp[505][505]; // dp[x][y] = the least energy which require reaching point "x" by passing not more than y node
// dp[v][x] = max(dp[u][x-1],dis(u,v))
long long dis(int u,int v){
    return abs(node[u].x-node[v].x)+abs(node[u].y-node[v].y);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>node[i].x>>node[i].y;
    }

    for(int v=0;v<n;v++){
        dp[v][1] = dis(0,v);
    }
    for(int x=2;x<=n;x++){
        for(int v=0;v<n;v++){
            dp[v][x] = 1e18+5;
            for(int u=0;u<n;u++){
                dp[v][x] = min(dp[v][x],max(dp[u][x-1],dis(u,v)));
            }
        }
    }

    long long sum = 0;
    while(m--){
        long long e; cin>>e;
        for(int x=1;x<=n;x++){
            if(dp[n-1][x]<=e){
                sum += x;
                break;
            }
        }
    }

    cout<<sum<<'\n';
}

/*
5 2
0 1
2 2
3 6
6 6
9 10
10
15
*/
/*
5 2
0 0
2 0
7 0
4 0
10 0
10 
3
*/