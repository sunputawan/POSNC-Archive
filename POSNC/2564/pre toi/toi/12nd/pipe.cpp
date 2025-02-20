#include <iostream>
#include <vector>
#include <queue>
#define INTMAX 999999

using namespace std;

vector<pair<int,int>> node;
int dis(int i,int j){
    return abs(node[i].first-node[j].first)+abs(node[i].second-node[j].second);
}
int d[20000];
bool visited[20000];
int n,k;
void printdis(void){
    for(int i=0;i<n;i++)
        cout<<i<<":"<<d[i]<<" ";
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        node.push_back({x,y});
    }
    for(int i=0;i<n;i++)
        d[i] = INTMAX;
    int pre=0;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int u = pre;
        int tmp = INTMAX;
        visited[u] = true;
        for(int v=0;v<n;v++){
            if(visited[v]) continue;
            int distance = dis(u,v);
            if(d[v]>distance){
                d[v] = distance;
            }
            if(tmp>d[v]){
                tmp=d[v];
                pre=v;
            }
        }
        pq.push(tmp);
    }
    while(k--){
        pq.pop();
    }
    int ans=0;
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans;
}
