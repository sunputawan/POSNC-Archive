#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> adj;
char name[] = {'S','A','B','C','D','E','F','G','H'};
int n=sizeof(name)/sizeof(name[0]);
void input_edge(void){
    adj.resize(n);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    //adj[1].push_back(3);
    adj[1].push_back(7);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[3].push_back(2);
    adj[3].push_back(8);
    adj[4].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(6);
    adj[7].push_back(4);
    adj[7].push_back(5);
    adj[8].push_back(1);
    adj[8].push_back(4);
}
void topological(void){
    vector<int> ans;
    bool available[n];
    for(int i=0;i<n;i++)
        available[i]=true;
    while(ans.size()<n){
        bool have_parent[n];
        for(int i=0;i<n;i++)
            have_parent[i]=false;
        for(int i=0;i<n;i++){
            if(!available[i])
                continue;
            for(auto v:adj[i])
                have_parent[v]=true;
        }
        for(int i=0;i<n;i++){
            if(!available[i])
                continue;
            if(!have_parent[i]){
                ans.push_back(i);
                available[i]=false;
            }
        }
    }
    for(auto v:ans){
        cout<<name[v]<<" -> ";
    }
}
int main(){
    input_edge();
    topological();
}
