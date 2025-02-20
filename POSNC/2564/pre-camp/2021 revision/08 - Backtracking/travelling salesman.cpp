#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#define INTMAX 99999

using namespace std;
vector<vector<pair<int,int>>> adj;
vector<int> min_bound,path,final_path;
char name[] = {'A','B','C','D','E'};
int n = sizeof(name)/sizeof(name[0]);
void make_edge(int u,int v,int e){
    adj[u].push_back({v,e});
    adj[v].push_back({u,e});
}
void input_edge(void){
    adj.resize(n);
    make_edge(0,1,1);
    make_edge(0,2,4);
    make_edge(0,3,6);
    make_edge(0,4,7);

    make_edge(1,2,5);
    make_edge(1,3,3);
    make_edge(1,4,4);

    make_edge(2,4,2);

    make_edge(3,4,1);
}
void show_graph(void){
    for(int u=0;u<n;u++){
        cout<<name[u]<<" -> ";
        for(auto v:adj[u])
            cout<<name[v.first]<<"("<<v.second<<"), ";
        cout<<endl;
    }
}
int lowest_possible_bound=0;
void find_bound(void){
    for(int u=0;u<n;u++){
        int low1 = INTMAX;
        int low2 = INTMAX;
        for(auto v:adj[u]){
            if(low1>v.second){
                low1=v.second;
            }
        }
        for(auto v:adj[u]){
            if(low2>v.second&&v.second!=low1){
                low2=v.second;
            }
        }
        min_bound.push_back(low1+low2);
        lowest_possible_bound+=low1+low2;
    }
    lowest_possible_bound++; lowest_possible_bound/=2;
}
int current_lowest_bound = INTMAX;
bool visited[sizeof(name)/sizeof(name[0])];
void TSP(int u,int current_bound,int current_weight,int level){
    cout<<"\nlevel : "<<level<<" "<<name[u]<<": curr_bound : "<<current_bound<<", curr_weight : "<<current_weight<<" {";
    for(auto v:path){
        cout<<name[v]<<", ";
    }
    cout<<'}';
    if(current_lowest_bound==lowest_possible_bound)
        return;
    if(level==n-1){
        bool source_path_exist = false;
        int source_index;
        for(int v=0;v<adj[u].size();v++){
            if(adj[u][v].first==0){
                source_path_exist=true;
                source_index=v;
                break;
            }
        }
        if(source_path_exist){
            int path_cost = current_weight+adj[u][source_index].second;
            cout<<"(BACK TO "<<name[0]<<"("<<adj[u][source_index].second<<"))";
            cout<<"\ncurrent weight : "<<path_cost<<endl;
            if(path_cost<current_lowest_bound){
                current_lowest_bound=path_cost;
                final_path=path;
            }
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<adj[u].size();i++){
        if(current_lowest_bound==lowest_possible_bound)
            return;
        int v = adj[u][i].first;
        if(visited[v]) continue;

        int tmp_bound = current_bound;
        current_bound-=min_bound[u];
        int selected_path = adj[u][i].second;
        int min=INTMAX;
        for(auto vpair:adj[u]){
            if(vpair.first!=adj[u][i].first&&vpair.second<min)
                min=vpair.second;
        }
        current_bound+=selected_path+min;
        current_weight+=selected_path;

        if(current_bound<current_lowest_bound){
            cout<<"(select : "<<name[adj[u][i].first]<<"("<<selected_path<<"))"<<endl;
            visited[v]=true;
            path.push_back(v);
            TSP(v,current_bound,current_weight,level+1);
            visited[v]=false;
            path.pop_back();
        }
        current_bound=tmp_bound;
        current_weight-=selected_path;
    }
}
void show_ans(void){
    cout<<"\n\nANS : "<<current_lowest_bound<<endl<<"Your Path : ";
    for(int u=0;u<final_path.size()-1;u++){
        cout<<name[final_path[u]]<<" --";
        int v=0;
        while(adj[final_path[u]][v].first!=final_path[u+1])
            v++;
        cout<<adj[final_path[u]][v].second<<"--> ";
    }
    cout<<name[0]<<endl;
}
int main(){
    input_edge();
    show_graph();
    find_bound();
    cout<<"Minimum Bound : "<<lowest_possible_bound<<endl<<endl;
    for(int i=0;i<n;i++)
        visited[i]=false;
    visited[0]=true;
    path.push_back(0);
    TSP(0,lowest_possible_bound,0,0);
    final_path.push_back(0);
    show_ans();
}
