#include <bits/stdc++.h>

using namespace std;
int n;
int a[9][9];
int init[9][9];
vector<pair<int,int>> st = {{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
bool check(void){
    unordered_set<int> s;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(init[i][j]!=a[i][j]&&init[i][j])
                return false;
        }
    }
    for(int i=0;i<9;i++){
        s.clear();
        for(int j=0;j<9;j++){
            s.insert(a[i][j]);
        }
        if(s.size()!=9)
            return false;
    }
    for(int j=0;j<9;j++){
        s.clear();
        for(int i=0;i<9;i++){
            s.insert(a[i][j]);
        }
        if(s.size()!=9)
            return false;
    }
    for(auto x:st){
        s.clear();
        for(int i=x.first;i<x.first+3;i++){
            for(int j=x.second;j<x.second+3;j++){
                s.insert(a[i][j]);
            }
        }
        if(s.size()!=9)
            return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cin>>init[i][j];
    }
    int x = 1;
    while(x<=n){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                cin>>a[i][j];
        }
        if(check())
            cout<<x<<endl;
        x++;
    }
    cout<<"END\n"<<endl;
}
