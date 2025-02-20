#include <bits/stdc++.h>

using namespace std;
set<int> s;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    while(m--){
        int a,b; cin>>a>>b;
        if(s.find(a)==s.end())
            s.insert(a);
        else
            s.erase(a);
        if(s.find(a+b)==s.end())
            s.insert(a+b);
        else
            s.erase(a+b);
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
