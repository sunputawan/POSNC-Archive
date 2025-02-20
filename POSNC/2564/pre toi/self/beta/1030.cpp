#include <bits/stdc++.h>

using namespace std;
int n,q;
double u,c;
priority_queue<pair<double,int>> pq;
int main(){
    cin>>n;
    while(n--){
        double u,v; cin>>u>>v;
        pq.push({-1*u/v,v});
    }

    cin>>q;
    while(q--){
        int cur; cin>>cur;
        double ans=0,sub;
        while(cur){
            double u;
            int v;
            u = pq.top().first;
            v = pq.top().second;
            pq.pop();

            sub = min(cur,v);
            cur-=sub;
            v-=sub;
            ans+=-1*u*sub;
            if(v){
                pq.push({u,v});
            }
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
}
