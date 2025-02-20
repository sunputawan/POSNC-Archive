#include <bits/stdc++.h>

using namespace std;
int m,n,t;
int a[105][50];
vector<int> v;
void car(int dis,int lane){
    if(dis==t){
        for(auto x:v){
            cout<<x<<'\n';
        }
        return;
    }

    if(lane>1 && a[dis+1][lane-1]!=1){
        v.push_back(1);
        car(dis+1,lane-1);
        v.pop_back();
    }
    if(a[dis+1][lane]!=1){
        v.push_back(3);
        car(dis+1,lane);
        v.pop_back();
    }

    if(lane<m && a[dis+1][lane+1]!=1){
        v.push_back(2);
        car(dis+1,lane+1);
        v.pop_back();
    }
}
int main(){
    cin>>m>>n>>t;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    car(0,n);
    return 0;
}