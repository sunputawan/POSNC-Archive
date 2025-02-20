#include <bits/stdc++.h>

using namespace std;
int first[9]={1,1,1,1,1,1,1,1,1};
bool visited[9];
int n,m;
vector<int> v;
void dfs(int u,int level){
    v.push_back(u);
    if(level==n){
        for(auto i:v)
            cout<<i<<" ";
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i,level+1);
        visited[i] = false;
    }
    v.pop_back();
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x; cin>>x;
        first[x] = 0;
    }
    for(int i=1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        if(!first[i]) continue;
        visited[i] = true;
        dfs(i,1);
    }
    return 0;
}
