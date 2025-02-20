#include <bits/stdc++.h>

using namespace std;
vector<pair<pair<int,int>,int>> v;
bool accepted[500005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++){
        int a,b; cin>>a>>b;
        v.push_back({{a,1},i});
        v.push_back({{b+1,-1},i});
    }
    sort(v.begin(),v.end());
    int sum=0;
    for(auto x:v){
        if(sum<k && x.first.second==1){
            sum++;
            accepted[x.second] = true;
        }
        else if(accepted[x.second]&&x.first.second==-1){
            sum--;
        }
    }
    while(m--){
        int q; cin>>q;
        if(accepted[q])
            cout<<"Y ";
        else
            cout<<"N ";
    }
}
