#include <bits/stdc++.h>

using namespace std;
vector<float> e[28][28]; // a,b,c,...,z = 0,1,2,...,25 X = 26, Y = 27
priority_queue<pair<float,int>> pq;
float g[28][28];
float dis[28];
int pre[28];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        char u,v; int w;
        cin>>u>>v>>w;
        if('a'<=u && u<='z') u -= 97;
        else if(u=='X') u = 26;
        else if(u=='Y') u = 27;

        if('a'<=v && v<='z') v-= 97;
        else if(v=='X') v = 26;
        else if(v=='Y') v = 27;

        e[u][v].push_back(w);
        e[v][u].push_back(w);
    }

    for(int i=0;i<28;i++){
        for(int j=0;j<28;j++){
            g[i][j] = -1;
            if(e[i][j].empty()) continue;
            sort(e[i][j].begin(),e[i][j].end());
            int num = e[i][j].size();
            if(num%2){
                g[i][j] = e[i][j][num/2];
            }
            else{
                g[i][j] = (e[i][j][(num-1)/2] + e[i][j][(num)/2])/2;
            }
        }
    }
    for(int i=0;i<28;i++){
        dis[i] = __INT_MAX__;
        pre[i] = -1;
    }
    dis[26] = 0; // X
    pq.push({dis[26],26});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(int v=0;v<28;v++){
            if(g[u][v]==-1) continue;
            if(dis[v]>dis[u]+g[u][v]){
                dis[v] = dis[u]+g[u][v];
                pre[v] = u;
                pq.push({dis[v],v});
            }
        }
    }

    if(dis[27]==__INT_MAX__){
        cout<<"broken\n";
        return 0;
    }
    vector<int> v;
    int a = 27;
    while(a!=-1){
        v.push_back(a);
        //cout<<a<<' '<<pre[a]<<'\n';
        a = pre[a];
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++){
        if(v[i]==26) cout<<"X ";
        else cout<<char(v[i]+97)<<' ';

        if(v[i+1]==27) cout<<"Y ";
        else cout<<char(v[i+1]+97)<<' ';

        printf("%.1f\n",g[v[i]][v[i+1]]);
    }

    printf("%.1f\n",dis[27]);
    return 0;
}

/*
7
X a 1
a X 7
a b 4
b a 1
b Y 3
b Y 2
Y b 6
*/