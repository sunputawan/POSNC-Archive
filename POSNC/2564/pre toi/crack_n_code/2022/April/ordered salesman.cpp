#include <bits/stdc++.h>

using namespace std;
long long a[401][401];
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)
                a[i][j] = INT_MAX;
        }
    }
    while(m--){
        long long u,v,w; cin>>u>>v>>w;
        a[u][v] = min(w,a[u][v]);
        a[v][u] = min(w,a[v][u]);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][k]==INT_MAX||a[k][j]==INT_MAX) continue;
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j] = a[i][k]+a[k][j];
            }
        }
    }
    long long ans = 0;
    for(int i=1;i<n;i++){
        ans += a[i][i+1];
    }
    cout<<ans<<endl;
    return 0;
}
