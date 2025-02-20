#include <bits/stdc++.h>

using namespace std;
int n,m,q;
map<int,int> mp;
int main(){
    cin>>n>>m>>q;
    mp[1] = 0;
    mp[n+1] = 0;
    while(m--){
        int s,e; cin>>s>>e;
        mp[s]++; mp[e+1]--;
    }
    int last = 0;
    int ans = 0;
    int sum = 0;
    int mx = 0;
    for(auto x:mp){
        if(last&&sum>mx){
            mx = sum;
            ans = x.first-last;
        }

        last = x.first;
        sum += x.second;
    }

    cout<<ans;
}
