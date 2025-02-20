#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
    int x,y,r;
    bool operator<(const point &o)const{
        return x<o.x||(x==o.x&&y<o.y);
    }
};
vector<point> v;
int sq(int n){
    return n*n;
}
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x,y,r; cin>>x>>y>>r;
        v.push_back({x,y,r});
    }
    sort(v.begin(),v.end());
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n&&(v[j].x-v[i].x<20);j++){
            if(sq(v[i].x-v[j].x)+sq(v[i].y-v[j].y)<sq(v[i].r+v[j].r))
                cnt++;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}