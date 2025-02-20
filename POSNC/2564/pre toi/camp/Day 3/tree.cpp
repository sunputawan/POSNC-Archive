#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()

using namespace std;
vector<pair<int,int>> t1,t2;
int main(){
    int n,u,v;
    cin.tie(0)->sync_with_stdio(0);
    int q = 5;
    while(q--){
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>u>>v;if(u>v) swap(u,v);
            t1.push_back({u,v});
        }
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            if(u>v) swap(u,v);
            t2.push_back({u,v});
        }
        sort(all(t1));
        sort(all(t2));
        if(t1==t2) cout<<"Y";
        else cout<<"N";
        t1.clear();
        t2.clear();
    }
    return 0;
}
