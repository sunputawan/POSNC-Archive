#include <bits/stdc++.h>

using namespace std;
priority_queue<int> pq;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        pq.push(x);
    }
    int i=0;
    int sum=0;
    while(!pq.empty()){
        if(i++%k==0)
            sum+=pq.top();
        pq.pop();
    }
    cout<<sum;
}
