#include <bits/stdc++.h>

using namespace std;
int n,m,q;
set<int> s;
int main(){
    cin>>n>>m>>q;
    while(m--){
        int u,v; cin>>u>>v;
        if(s.find(u)==s.end())
            s.insert(u);
        else
            s.erase(u);
        if(s.find(u+v)==s.end())
            s.insert(u+v);
        else
            s.erase(u+v);
    }
    s.insert(1);
    s.insert(n+1);
    while(q--){
        int x; cin>>x;
        auto l = s.lower_bound(x);
        auto r = s.upper_bound(x);
        if(*l==*r)
            l--;
        cout<<*r-*l<<endl;
    }
    return 0;
}
