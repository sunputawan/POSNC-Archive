#include <iostream>
#include <utility>
#include <queue>

using namespace std;
int n,x,y,tx,ty;
vector<pair<int,int>> dir={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
bool visited[100][100];
struct coor{
    int x,y,count;
};
queue<coor> q;
int main(){
    int n;
    cout<<"Enter n : "; cin>>n;
    cout<<"Enter start : "; cin>>x>>y;
    cout<<"Enter destination : ";cin>>tx>>ty;
    q.push({x,y,0});
    while(!q.empty()){
        int currx = q.front().x;
        int curry = q.front().y;
        int currcount = q.front().count;
        //cout<<"pop : "<<currx<<" "<<curry<<endl;
        q.pop();
        if(currx==tx&&curry==ty){
            cout<<"Minimum round : "<<currcount<<endl;
            return 0;
        }
        if(currx<0||currx>=n||curry<0||curry>=n) continue;

        if(visited[currx][curry])
            continue;

        visited[currx][curry] = true;
        for(auto d:dir){
            //cout<<"push : "<<currx+d.first<<" "<<curry+d.second<<endl;
            q.push({currx+d.first,curry+d.second,currcount+1});
        }
    }
}
