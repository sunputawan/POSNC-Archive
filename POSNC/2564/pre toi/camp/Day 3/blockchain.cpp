#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> e;
map<vector<pair<int,int>>,int> mp;
int main(){
    int t,q;
    cin>>t>>q;
    int n,u,v;
    while(t--){
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            if(u>v) swap(u,v);
            e.push_back({u,v});
        }
        sort(e.begin(),e.end());
        mp[e]++;
        e.clear();
    }
    while(q--){
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            if(u>v) swap(u,v);
            e.push_back({u,v});
        }
        sort(e.begin(),e.end());
        if(mp[e])
            cout<<mp[e]<<'\n';
        else
            cout<<"0\n";
        e.clear();
    }
    return 0;
}
