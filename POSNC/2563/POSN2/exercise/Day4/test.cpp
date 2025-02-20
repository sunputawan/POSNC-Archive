#include <iostream>
#include <vector>
#include <set>
#include <utility>
#define inf 9999999

using namespace std;
vector<vector<pair<int,int>>> adj;

int main(){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
