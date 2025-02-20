#include <bits/stdc++.h>

using namespace std;
int m,n,t;
int a[105][45];
vector<int> v;
void dfs(int x,int level){
    if(level==t){
        for(auto i:v)
            cout<<i<<endl;
        return;
    }
    if(!a[level+1][x-1]&&x>1){
        v.push_back(1);
        dfs(x-1,level+1);
        v.pop_back();
    }
    if(!a[level+1][x+1]&&x<m){
        v.push_back(2);
        dfs(x+1,level+1);
        v.pop_back();
    }
    if(!a[level+1][x]){
        v.push_back(3);
        dfs(x,level+1);
        v.pop_back();
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>m>>n>>t;
    int des;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    dfs(n,0);
    cout<<endl;
    return 0;
}
