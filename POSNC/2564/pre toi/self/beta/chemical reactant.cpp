#include <bits/stdc++.h>

using namespace std;
vector<int> v;
vector<int> r;
map<vector<int>,int> mp;
int main(){
    int n,p;
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        v.clear();
        for(int j=0;j<p;j++){
            int x; cin>>x;
            v.push_back(x);
        }
        mp[v] = i;
    }
    r.resize(p);
    for(int j=0;j<p;j++){
        cin>>r[j];
    }
    if(mp.count(r)){
        cout<<mp[r]<<'\n';
        return 0;
    }
    for(auto x:mp){
        auto vec = x.first;
        auto idx = x.second;
        vector<int> tmp(p);
        for(int j=0;j<p;j++){
            tmp[j] = r[j]-vec[j];
        }
        if(mp.count(tmp)&&mp[tmp]!=idx){
            cout<<min(idx,mp[tmp])<<' '<<max(idx,mp[tmp])<<'\n';
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}
