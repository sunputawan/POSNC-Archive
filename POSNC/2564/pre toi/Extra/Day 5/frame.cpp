#include <bits/stdc++.h>

using namespace std;
int n,m;

vector<vector<int>> v;
int main(){
    int x1,x2,y1,y2;
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>x1>>y1>>x2>>y2;
        v[i].push_back(x1);
        v[i].push_back(y1);
        v[i].push_back(x2);
        v[i].push_back(y2);
    }
    while(m--){
        int a1,b1,a2,b2;
        cin>>a1>>b1>>a2>>b2;
        int cnt = 0;
        for(int i=0;i<n;i++){
            x1 = v[i][0];
            y1 = v[i][1];
            x2 = v[i][2];
            y2 = v[i][3];

            bool x = (a1<x2&&a2>x1);
            bool y = (b1>y2&&b2<y1);
            if(x&&y){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
