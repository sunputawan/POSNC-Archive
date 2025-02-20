#include <iostream>
#define INTMAX 99999999999

using namespace std;
int path[11][11]={};
struct items{
    int m,k,c;
}store[11];
struct cost{
    int x,y,z;
}coor[11];
int find_dis(int i,int j){
    int x1 = coor[i].x,x2 = coor[j].x;
    int y1 = coor[i].y,y2 = coor[j].y;
    int z1 = coor[i].z,z2 = coor[j].z;

    int a = (x1-x2)*(x1-x2);
    int b = (y1-y2)*(y1-y2);
    int c = (z1-z2)*(z1-z2);

    return a+b+c;
}
int n,m;
long long dis=INTMAX;
bool visited[11];
void explore(int curr,long long currdis,int mon,int key,int cas){
    if(currdis>dis)
        return;
    if(min(mon,min(key,cas))>=n){
        dis = min(dis,currdis);
        return;
    }
    for(int i=1;i<=m;i++){
        if(visited[i]||i==curr) continue;
        int newdis = currdis+path[curr][i];
        int newmon = mon+store[i].m;
        int newkey = key+store[i].k;
        int newcas = cas+store[i].c;
        visited[i] = true;
        explore(i,newdis,newmon,newkey,newcas);
        visited[i] = false;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    int xx,yy,zz; cin>>xx>>yy>>zz;
    coor[0] = {xx,yy,zz};
    cin>>m;
    for(int i=1;i<=m;i++){
        int x,y,z; cin>>x>>y>>z;
        int m,k,c; cin>>m>>k>>c;
        coor[i] = {x,y,z};
        store[i] = {m,k,c};
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            path[i][j] = find_dis(i,j);
        }
    }
    explore(0,0,0,0,0);
    cout<<dis;
}
