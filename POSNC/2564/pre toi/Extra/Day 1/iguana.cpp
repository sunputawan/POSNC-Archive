#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> v;
int color[3];
int main(){
    int n,m;
    cin>>n>>m;
    v.push_back({1,0});
    v.push_back({n+1,0});
    while(m--){
        int a,b; cin>>a>>b;
        v.push_back({a,1});
        v.push_back({b+1,-1});
    }
    sort(v.begin(),v.end());
    int last = 0;
    int sum=0;
    for(auto x:v){
        if(last){
            color[(sum%3+3)%3]+=x.first-last;
        }
        sum+=x.second;
        last=x.first;
    }
    char c; cin>>c;
    int ans = 0;
    if(c=='R')
        ans = color[1]*2+color[2];

    else if(c=='G')
        ans = color[0]+color[2]*2;

    else
        ans = color[0]*2+color[1];

    cout<<ans<<endl;
    return 0;;
}
