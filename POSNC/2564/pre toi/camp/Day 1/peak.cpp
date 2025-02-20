#include <bits/stdc++.h>

using namespace std;
int h[5000005];
priority_queue<int> pq;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    h[n+1] = 0;
    h[0] = 0;
    for(int i=1;i<=n;i++){
        if(h[i]>h[i-1]&&h[i]>h[i+1])
            pq.push(h[i]);
    }
    if(pq.size()==0){
        cout<<-1;
        return 0;
    }
    int curr = 0;
    while(!pq.empty()&&k){
        if(curr!=pq.top()){
            k--;
            curr = pq.top();
            v.push_back(curr);
        }
        pq.pop();
    }
    if(k!=0){
        for(int i=v.size()-1;i>=0;i--)
            cout<<v[i]<<'\n';
    }
    else{
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<'\n';
    }
    return 0;
}
