#include <bits/stdc++.h>

using namespace std;
int hor[105][105];
int ver[105][105];
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
    int n,k; cin>>n>>k;
    for(int j=0;j<n;j++)
        cin>>hor[0][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin>>ver[i][j];
        }
        for(int j=0;j<n;j++){
            cin>>hor[i+1][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x = 3*(hor[i][j]-hor[i+1][j])+5*(ver[i][j]-ver[i][j+1]);
            pq.push(x);
        }
    }

    int sum = 0;
    while(k--){
        sum+=pq.top();
        pq.pop();
    }
    cout<<sum;
}
