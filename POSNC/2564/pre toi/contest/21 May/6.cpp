#include <bits/stdc++.h>

using namespace std;
long long r[25],n,w;
long long play(long long level,long long w){
    if(w<=0) return -1;
    if(level == 1) return w;
    long long now = w*2-r[level]+1,a,b;
    a = play(level-1,now/2);
    b = play(level-1,now-(now/2));
    if(a==-1)
        return -1;
    return a+b;
}
int main(){
    int q; cin>>q;
    while(q--){
        cin>>n>>w;
        for(int i=2;i<=n;i++){
            cin>>r[i];
        }
        long long ans = play(n,w);
        cout<<ans<<'\n';
    }
    return 0;
}
