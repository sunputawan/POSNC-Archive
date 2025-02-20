#include <bits/stdc++.h>

using namespace std;
int mark[1005][1005],cnt;
int main(){
    int n; cin>>n;
    while(n--){
        int x,y; cin>>x>>y;
        if(!mark[x][y]){
            mark[x][y] = 1;
            cnt++;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}