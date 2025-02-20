#include <bits/stdc++.h>

using namespace std;
int m,n,p;
struct coor{
    int x,y,val;
    bool operator<(const coor& o){
        x<o.x;
    }
};
vector<struct p> a;
int dp[1000005];
int dif[1000005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>m>>n>>p;
    while(p--){
        int x,y,num;
        cin>>x>>y>>num;
        a.push_back({x,y,num});
    }
    sort(a.begin(),a.end());
    for(int i=0;i<a.size()-1;i++){
        dif[i] = a[i+1].y-a[i].y;
    }
    return 0;
}
